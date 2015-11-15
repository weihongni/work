#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */

#define SERV_IP "192.168.7.6"
#define SERV_PORT 5001

#define QUIT_STR "quit"

int main(void)
{
        int fd = -1, ret = -1;
	char buf[BUFSIZ];

        struct sockaddr_in sin;

        /* 1.创建套接字*/
        if( (fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("socket");
                exit(1);
        }

	/* 2. 连接到服务器 */
	 /*2.1 填充sockaddr_in结构体，填充服务器的IP地址和端口号 */
        sin.sin_family = AF_INET;
        sin.sin_port = htons(SERV_PORT);
        sin.sin_addr.s_addr = inet_addr(SERV_IP);
        
	bzero(sin.sin_zero, 8);

	if ( connect(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
		perror("connect");
		exit(EXIT_FAILURE);
	}

	printf("Simple TCP demo starting ....OK!\n");
        
	/* 3. 写套接字 */
        /* 从标准键盘上读入数据,写入套接字，直到用户输入quit就退出 */
        while (1) {
                fprintf (stderr, "writer: please input string:");
                bzero (buf, BUFSIZ);
                if (fgets (buf, BUFSIZ - 1, stdin) == NULL) {
                        perror ("fgets");
                        continue;
                }

                do {
                        ret = write (fd, buf, strlen (buf));    
                } while (ret < 0 && EINTR == errno);
                if (ret < 0) {
                        perror ("write");
                        continue;
                }

                if (!ret || !strncasecmp (buf, QUIT_STR, strlen (QUIT_STR))) {  //用户输入quit
                        break;
                }
        }

        close (fd);
}
