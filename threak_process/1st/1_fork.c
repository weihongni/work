#include<stdio.h>

int main(void)
{
	pid_t pid = -1;
	printf("I'm parent process!\n");
	pid = fork();
	if(pid<0){
		perror("fork");
		exit(1);
	}
	if(pid>0){
		
	}

	return 0;
}
