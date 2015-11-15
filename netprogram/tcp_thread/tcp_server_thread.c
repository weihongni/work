#include "net.h"
void *cli_data_handler(void *arg);

int main (void)
{
	int ret = -1;
	int fd = -1, newfd = -1;
	struct sockaddr_in sin;
	
	//信号处理
        //..

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
	
	cinfo.cli_fd = newfd;
	memcpy(&cinfo.cin, &cin, sizeof(cin));
	pthread_create(&tid, NULL, cli_data_handler, (void *)&cinfo);

}
	close (fd);
	return 0;
}

void *cli_data_handler(void *arg)
{
	
	int newfd = -1, ret = -1;
	char cli_ip_addr[16];
	struct cli_info *pinfo = (struct cli_info *)arg; 
	struct sockaddr_in cin;
        char buf[BUFSIZ];
	
	if(!pinfo) return NULL;
	
	pthread_detach(pthread_self());
	
	newfd = pinfo->cli_fd;
        memcpy(&cin, &pinfo->cin, sizeof(cin));
	
	 /*5.和客户端进行数据交互 */
        //....

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

                        /*6.数据交互完成，关闭套接字 */
                        close (newfd);
                        break;
                }

        }
	
	return NULL;
}

