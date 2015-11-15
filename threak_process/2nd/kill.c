/*用父子进程实现一个匿名管道：子进程写，父进程读  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>
#include <string.h>
#include <signal.h>

int main (void)
{
	pid_t pid = -1;

	printf ("kill demo\n");

	pid = fork ();				/*创建子进程 */
	switch (pid) {
		case -1:
			perror ("fork");
			exit (1);
			break;

		case 0:	//子进程
			printf("Child: pid =%d, ppid=%d\n", getpid(), getppid());
			raise(SIGSTOP);  /* 给自己发一个SIGSTOP停止信号*/
			printf("Child process exit\n");
			exit (EXIT_SUCCESS);
			break;

		default://父进程
			printf("Parent: pid =%d\n", getpid());
			sleep(1); //让子进程先运行
			if( waitpid(pid, NULL, WNOHANG) == 0) { /* 子进程没退出 */
				kill(pid, SIGKILL);
			} 
			printf("Parent: killed %d\n", pid);
			exit (EXIT_SUCCESS);
			break;
	}


	return 0;
}
