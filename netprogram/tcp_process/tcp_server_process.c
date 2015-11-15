#include <signal.h> 

#include "net.h"
void *cli_data_handler(struct cli_info *pinfo);

void sig_child_handler(int signo)
{
	int status;
	int pid = wait(&status);  //wait()在此不会阻塞！！
	printf("Child pid=%d is exited.\n", pid); /* 建议不使用 */
}

int main (void)
{
	int ret = -1;
	int fd = -1, newfd = -1;
	struct sockaddr_in sin;
	
	//信号处理
#if 0
        signal(SIGCHLD, sig_child_handler);
#else
	/*对SIGCHLD信号做处理，使得fork()时，父进程不需要wait()/waitpid() */ 
	struct sigaction act;
	act.sa_handler = SIG_DFL;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART|SA_NOCLDWAIT;
	sigaction(SIGCHLD, &act,NULL);
#endif
	/*1. 建立套接字 */
	if ((fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)	//ipV4的TCP编程
	{
		perror ("socket");
		exit (1);
	}
       /* 允许地址快速重用 **/       
        int b_reuse =1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &b_reuse, sizeof(int));

	/*2.绑定本机IP和端口号 */
	/* 2.1 填充sockaddr_In结构体 */
	bzero (&sin, sizeof (sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons (SERV_PORT);
#if 0	
	sin.sin_addr.s_addr = inet_addr (SERV_IP);
#else
	sin.sin_addr.s_addr = INADDR_ANY; /* 绑定在本机的任意IP上 */
#endif
	/*2.2 绑定 */
	if (bind (fd, (struct sockaddr *) &sin, sizeof (sin)) < 0) {
		perror ("shyi- bind error");
		exit (1);
	}

	/*3.把套接字变为被动套接字 */
	if (listen (fd, BACKLOG) < 0) {
		perror ("listen");
		exit (1);
	}


	printf ("Server starting....OK!\n");
	
	/* 4. 阻塞等待客户端链接 */
	/*取客户端信息 */
	struct sockaddr_in cin;
	socklen_t cli_len = sizeof (cin);

while (1) {	
	
	pthread_t tid;
	struct cli_info cinfo;
	
	newfd = accept (fd, (struct sockaddr *) &cin, &cli_len);
	if (newfd < 0) {
		perror ("accept error");
		exit (1);	
	}

	int pid = -1;
        cinfo.cli_fd = newfd;
	memcpy(&cinfo.cin, &cin,sizeof(cin));

	if( (pid = fork()) <0 ) {
		perror("fork error");
		continue;
	}
	
	if(pid > 0)  {  //父进程
		//记录子进程的pid和使用的文件描述符
		//把cinfo项记录在内核链表中
	}
	
	if(pid  == 0) { //子进程 
	    	void *pRet = NULL;
		close(fd);
	        pRet = cli_data_handler(&cinfo);  	
	        close(newfd);
		return (int)pRet;	
	}	


}
	close (fd);
	return 0;
}


void *cli_data_handler(struct cli_info *pinfo)
{
        int ret, newfd = -1;
	struct sockaddr_in cin;
        char buf[BUFSIZ];
	char cli_ip_addr[16];

        if(!pinfo) return NULL;


        newfd = pinfo->cli_fd;
        memcpy(&cin, &pinfo->cin, sizeof(cin));

	
	if( (newfd > 0) && (inet_ntop(AF_INET, (void *)&cin.sin_addr, cli_ip_addr, sizeof(cin)) != NULL) ) {
                printf("A new(ip =%s, port =%d) client conneted.\n", cli_ip_addr, ntohs(cin.sin_port) );
        } else {
                perror("inet_ntop() error");
        }

        while (1) {
                bzero (buf, BUFSIZ);
                do {
                        ret = read (newfd, buf, BUFSIZ - 1);
                } while (ret < 0 && EINTR == errno);

                if (ret < 0) {
                        perror ("read error");
                        exit (1);                       //FIXME!!!!, there is a bug
                }
                if (ret == 0) {
                        printf ("Client is exited.");
                }

                printf ("Received data: %s\n", buf);


                if(!strncasecmp(buf, QUIT_STR, strlen(QUIT_STR))) { /* 用户输入了quit*/
                        break;
                }

        }

	return NULL;
}



