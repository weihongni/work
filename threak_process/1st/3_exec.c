#include<stdio.h>
#include<unistd.h>

int main(void)
{
//	char *argv[]={"ls","-al","/etc/passwd",NULL};
//	execvp("ls",argv);
#if 0
	if(execlp("ls","ls","-al","/etc/passwd",NULL)<0)
		perror("execlp error!");
#else
	char *argv[]={"ls","-al","/etc/passwd",NULL};
	execv("/bin/ls",argv);
#endif

	return 0;
}
