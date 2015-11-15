#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	int result;
	pid_t pid;
	if((pid=fork()==-1)){
		perror("fork");
		exit(-1);
	}
	else if(pid == 0){
		result = 5;
		printf("The return value is %d\nInchild process!!\nMyPID is %d\n",result,getpid());
	}
	else{
		result = 7;
		printf("The return value is %d\nIn father process!!\nMyPID is%d\n",result,getpid());
	}

	return 0;
}
