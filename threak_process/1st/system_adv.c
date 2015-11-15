#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int status;
	printf("system() demo!\n");
	
	status = system("ls -al");
	

	printf("Command exit value: %d\n", WEXITSTATUS(status));
	//查看子进程的退出
	if(WIFEXITED(status)) {
	   printf("the child terminated normally!\n");
	}
	if(WIFSIGNALED(status)) {
		     printf("the child process was terminated by a signal!\n");
	}


	return 0;

}
