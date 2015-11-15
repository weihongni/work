#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int a = 3;  /* .data */
int b;      /*.bss */

int main(void)
{

	int c = 4; /* stack */
	
	static int d = 5; /* .data */


	pid_t pid = -1;

	printf("I'm parent process!\n");
	
	pid = fork();
	if(pid < 0 ) { //出错
		perror("fork");
		exit(1);
	}		

	printf("aaaa\n");	

	if(pid > 0) { //父进程中的返回
		usleep(100000); //0.1s,让子进程先运行 
		printf("I'm parent, pid =%d, child process PID =%d\n", getpid(), pid);
		
		a += 3;
		b += 3;
		c += 3;
		d += 3;

		printf("parent process: a=%d, b=%d ,c =%d, d=%d\n", a, b, c, d);
	} else {  // 0 = pid,子进程中返回 
		printf("I'm child process, pid =%d, ppid=%d\n", getpid(), getppid());
		a += 5;
		b += 5;
		c += 5;
		d += 5;

		printf("child process: a=%d, b=%d ,c =%d, d=%d\n", a, b, c, d);
	}	

	return 0;
}
