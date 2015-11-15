#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pc = -1;

	pc = fork();
	if(pc < 0 ) { //出错
		perror("fork");
		exit(1);
	}		

	printf("aaaa\n");	

	if(pc > 0) { //父进程中的返回
		int status,pr = 0;
		while(pr == 0){
			pr = waitpid(-1, &status, WNOHANG); //非阻塞等待子进程退出
			sleep(1);
			printf("I'm parent, pid =%d, child process PID =%d\n", getpid(), pc);
		}
		if(WIFEXITED(status)) {
			printf("the child terminated normally!\n");	
		}	
	} else {  // 0 = pc,子进程中返回 
		sleep(5);
		printf("I'm child process, pid =%d, ppid=%d\n", getpid(), getppid());
	}	

	return 0;
}
