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
#include <sys/sem.h>

#include "sem_com.h"

#define QUIT_STR "quit"

#define SHM_SIZE BUFSIZ

int main (void)
{
	int shm_id = -1;
	int sem_id = -1;

	char *shm_buf = NULL;

	/* 1.创建共享内存和获取信号量 */
	if ((shm_id = shmget (ftok (".", 'a'), SHM_SIZE, IPC_CREAT | 0666)) < 0) {
		perror ("shmget");
		exit (EXIT_FAILURE);
	}
	if((sem_id = semget(ftok(".", 'b'), 1, IPC_CREAT|0666)) < 0) {
		perror ("semget");
		exit (EXIT_FAILURE);

	}
	/* 2、初始信号量和映射共享内存到用户空间 */
	init_sem(sem_id, 0, 1);	

	shm_buf = (char *) shmat (shm_id, NULL, 0);
	if (shm_buf == (void *) -1) {
		perror ("shmat");

		//FIMXE!!! 
		//是否要删除共享内存

		exit (EXIT_FAILURE);
	}


	/*3. 使用 */
	printf ("Share Memory writer starting ....OK!\n");
	char buf[BUFSIZ];

	/* 从标准键盘上读入数据,写入管道，直到用户输入quit就退出 */
	while (1) {
		fprintf (stderr, "writer: please input string:");

		bzero(buf, BUFSIZ);

		if (fgets (buf, BUFSIZ - 1, stdin) == NULL) {
			perror ("fgets");
			continue;
		}

		//P操作
		sem_p(sem_id, 0,1);

		strncpy(shm_buf, buf, strlen(buf));

		if (!strncasecmp (shm_buf, QUIT_STR, strlen (QUIT_STR))) {	//用户输入quit
			//V操作
			sem_v(sem_id, 0, 1);
			break;
		}
		//V操作
		sem_v(sem_id, 0, 1);
	}


	/* 4.撤销映射 */
	shmdt(shm_buf);

	/* 删除共享内存和信号量 */
	//shmctl (shm_id, IPC_RMID, NULL);
	//sem_del(sem_id);

	return 0;
}
