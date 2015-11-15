#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{
	pid_t pid;
	int ret;
	if((pid=fork())<0){
		perror("fork");	
		exit(1);
	}
	if(pid == 0){
		raise(SIGSTOP);
		printf("child process exit...\n");
		exit(0);
	}
	else{
		printf("pid=%d\n",pid);
		if((waitpid(pid,NULL,WNOHANG)) == 0){
			kill(pid,SIGKILL);
			printf("kill %d\n",pid);
		}
	}

	return 0;
}
