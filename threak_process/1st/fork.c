#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid = -1;

	printf("I'm parent process!\n");
	
	pid = fork();
	if(pid < 0 ) { //出错
		perror("fork");
		exit(1);
	}		

	printf("aaaa\n");	

	if(pid > 0) { //父进程中的返回
//		usleep(100000); //0.1s,让子进程先运行 
		printf("I'm parent, pid =%d, child process PID =%d\n", getpid(), pid);
	} else {  // 0 = pid,子进程中返回 
		printf("I'm child process, pid =%d, ppid=%d\n", getpid(), getppid());
	}	

	return 0;
}
