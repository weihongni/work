#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "sem_com.h"

/* 初始化信号量函数*/
int init_sem (int semid, int sem_num, int val)
{
	union semun sun;
	sun.val = val;
	return semctl (semid, sem_num, SETVAL, sun);
}

/* 删除信号量 */
int sem_del(int semid) 
{
	union semun sun;
	return semctl (semid, 0, IPC_RMID, sun);

}

/**  P操作
 * 参数：
 *    semid:  信号量的id
 *    sem_num: 要操作的信号量的编号(也就是内核数组的下标)
 *    nops: 一次要操作几个资源(要操作的数组下标的个数)，一般为1
 */
int sem_p (int semid, short sem_num, size_t nops)
{
	struct sembuf sops;

	sops.sem_num = sem_num;		/* 数组下标 */
	sops.sem_op = -1;
	sops.sem_flg = SEM_UNDO;

	return semop (semid, &sops, nops);
}


/**  V操作
 * 参数：
 *    semid:  信号量的id
 *    sem_num: 要操作的信号量的编号(也就是内核数组的下标)
 *    nops: 一次要操作几个资源(要操作的数组下标的个数)，一般为1
 */
int sem_v (int semid, short sem_num, size_t nops)
{
	struct sembuf sops;

	sops.sem_num = sem_num;		/* 数组下标 */
	sops.sem_op = 1;
	sops.sem_flg = SEM_UNDO;

	return semop (semid, &sops, nops);
}

/**  P操作非阻塞版本
 * 参数：
 *    semid:  信号量的id
 *    sem_num: 要操作的信号量的编号(也就是内核数组的下标)
 *    nops: 一次要操作几个资源(要操作的数组下标的个数)，一般
 */
int sem_try_p (int semid, short sem_num, size_t nops)
{
	struct sembuf sops;

	sops.sem_num = sem_num;		/* 数组下标 */
	sops.sem_op = -1;
	sops.sem_flg = IPC_NOWAIT | SEM_UNDO;

	return semop (semid, &sops, nops);
}


