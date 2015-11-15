#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "net.h"

int main (void)
{
	int ret = -1;
	int fd = -1;

	fd_set rset;
	int maxfd;
	struct sockaddr_in sin;

	/* 信号处理 */
	//...FIXME!!!

	/*1. 建立套接字 */
	if ((fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)	//ipV4的TCP编程
	{
		perror ("socket");
		exit (1);
	}

	/*2.连接服务器 */
	/*2.1 填充要连接的服务器信息 */
	bzero (&sin, sizeof (sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons (SERV_PORT);
	sin.sin_addr.s_addr = inet_addr (SERV_IP);
	/*2.2 连接服务器 */
	if (connect (fd, (struct sockaddr *) &sin, sizeof (sin)) < 0) {
		printf ("Client didn't conneted Server!\n");
		perror ("connet");
		exit (1);
	}
	printf("Client is started....OK!\n");

	char buf[BUFSIZ];

	while (1) {
		FD_ZERO (&rset);
		FD_SET (0, &rset);
		FD_SET (fd, &rset);
		maxfd = fd;
		fprintf(stderr,"please input string:");
	
		select (maxfd + 1, &rset, NULL, NULL, NULL);
		
		if (FD_ISSET (0, &rset)) {	//标准输入
			bzero (buf, BUFSIZ);
			if (fgets (buf, BUFSIZ - 1, stdin) == NULL) {	/* 从标准输入端获取了了键盘输入 */
				perror ("fgets error");
				continue;
			}
			/* 按协议封包，写到套接字上去 */
			//...FIXME!!! 协议封包
			do {
				ret = write (fd, buf, strlen (buf));
			} while (ret < 0 && EINTR == errno);
			if (ret < 0) {
				perror ("write to socket error");
				continue;
			}

			if (!strncasecmp (buf, QUIT_STR, strlen (QUIT_STR))) {	/* 用户输入了quit */
				break;
			}

		}

		if(FD_ISSET(fd, &rset)) { /* 服务器发送过来了数据*/
		     	 bzero(buf, BUFSIZ);
			 do {
                                ret = read(fd, buf, BUFSIZ);
                         } while (ret < 0 && EINTR == errno);
                        if (ret < 0) {
                                perror ("write to socket error");
                                continue;
                        }
			printf("Received data from server:%s\n", buf);

                        if (!strncasecmp (buf, QUIT_STR, strlen (QUIT_STR))) {  /* 服务器退出 */
                                printf("Server is exiting....\n");
				break;
                        }

		}
	}
	close (fd);

	return 0;
}
