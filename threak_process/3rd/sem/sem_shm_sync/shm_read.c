#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/ipc.h>
#include <sys/shm.h>

#define QUIT_STR "quit"

#define SHM_SIZE BUFSIZ

int main (void)
{
	int shm_id = -1;
	int sem_w = -1, sem_r = -1;

	char *shm_buf = NULL;

	/* 1.打开共享内存 */
	if ((shm_id = shmget (ftok (".", 'a'), SHM_SIZE, IPC_CREAT | 0666)) < 0) {
		perror ("shmget");
		exit (EXIT_FAILURE);
	}
	/* 打开信号量 */
	sem_w = semget(ftok(".", 'b'), 1, IPC_CREAT|0666);
	sem_r = semget(ftok(".", 'c'), 1, IPC_CREAT|0666);

	if(sem_w < 0 || sem_r < 0) {
		perror ("semget");
		exit (EXIT_FAILURE);
	}


	/*2.映射共享内存到用户空间 */
	shm_buf = (char *) shmat (shm_id, NULL, 0);
	if (shm_buf == (void *) -1) {
		perror ("shmat");

		//FIMXE!!! 
		//是否要删除共享内存

		exit (EXIT_FAILURE);
	}


	/*3. 使用 */
	printf ("Share Memory reader starting ....OK!\n");

	/* 从标准键盘上读入数据,写入管道，直到用户输入quit就退出 */
	while (1) {
		//P操作
		sem_p(sem_r, 0,1);

		if (shm_buf[0]) {
			printf ("Read share Memory data: %s\n", shm_buf);

			if (!strncasecmp (shm_buf, QUIT_STR, strlen (QUIT_STR))) {	//用户输入quit
				//v操作
				sem_v(sem_w, 0, 1);

				break;
			}
			bzero (shm_buf, BUFSIZ);
		}
		//v操作
		sem_v(sem_w, 0, 1);

		//		usleep (200000);		//sleep 0.2s
	}


	/* 4.撤销映射 */
	shmdt (shm_buf);

	/* 删除共享内存和信号量 */
	shmctl (shm_id, IPC_RMID, NULL);
	sem_del(sem_w);
	sem_del(sem_r);


	return 0;
}
