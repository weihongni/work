#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <strings.h>

void ctrl_c_handler(int signo)
{
	if(signo == SIGINT) {
		printf("Receive a SIGINT signal");
	}	

}

int main(void)
{
	struct sigaction act;
	sigset_t set;
		
	printf("sigprocmask() demo\n");
	
	/* 处理SIGCHLD信号，让子进程退出时，避免子进程成为僵尸进程*/
	bzero(&act, sizeof(act));
	act.sa_handler = SIG_DFL;
	act.sa_flags   = SA_RESTART|SA_NOCLDWAIT;
        sigaction(SIGCHLD, &act, NULL);
	
	/*1. 阻塞 SIGINT,SIGQUIT信号*/
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	sigprocmask(SIG_BLOCK, &set, NULL);
#if 0	
	/* 2.1 安装SIGQUIT处理句柄(忽略), 安装处理句柄时，临时阻塞SIGINT,SIGQUIT */
	act.sa_handler = SIG_IGN;
        act.sa_flags   = SA_RESTART;
	sigemptyset(&act.sa_mask);
        sigaddset(&act.sa_mask, SIGINT);
        sigaction(SIGQUIT, &act, NULL);

	/* 2.2 安装SIGINT信号处理句柄，安装过程中，临时阻塞SIGQUIT和SIGINT*/
	act.sa_handler = ctrl_c_handler;
	act.sa_flags = SA_RESTART; /* 快速"重启"*/
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	sigaction(SIGINT, &act, NULL);
#else
       signal(SIGQUIT, SIG_IGN); /* 2. 忽略信号  IGN: ignore*/
       signal(SIGINT, ctrl_c_handler);/* 3. 捕获信号*/

#endif
	/*3.放开SIGINT,SIGQUIT信号 */
	sigprocmask(SIG_UNBLOCK, &set, NULL);
	
	/*4. 检测系统中是否有阻塞期间产生的SIGINT和SIGQUIT,如有，现在可以送过来处理 */
	sigpending(&set);

	while(1) {
		printf("I'm in loop\n");
		usleep(200000); //sleep 0.2s
	}
	
	return 0;
}	
