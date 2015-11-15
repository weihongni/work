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
#include <arpa/inet.h>

#define QUIT_STR "quit"

#define SERV_IP "192.168.7.6"
#define SERV_PORT 5001
#define BACKLOG 5
int main(void)
{
	int fd = -1, newfd = -1;

	struct sockaddr_in sin;

        /* 1.创建套接字*/	
	if( (fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}

	/* 2. 绑定 */
	/*2.1 填充sockaddr_in结构体，填充绑定的IP地址和端口号 */
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
#if 0
	sin.sin_addr.s_addr = inet_addr(SERV_IP);
#else 
	if(inet_pton(AF_INET,SERV_IP, &sin.sin_addr) != 1) {
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}
#endif
	//sin.sin_addr.s_addr = htonl(INADDR_ANY);

	bzero(sin.sin_zero, 8); 

	/* 允许地址快速重用 **/       
	int b_reuse =1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &b_reuse, sizeof(int));

	/* 2.2 调用bind()函数去绑定在本地的某个IP地址+端口上*/
	if(bind(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	/* 3.把套接字变成被动套接字 */
	listen(fd, BACKLOG);

	/*4. 阻塞等待客户端连接 */
#if 0
	newfd = accept(fd, NULL, NULL);
#else
	struct sockaddr_in cin;	
	int clen = sizeof(cin);
	newfd = accept(fd, (struct sockaddr *)&cin, &clen);

	char cli_ip_addr[16];
	if( inet_ntop(AF_INET, &cin.sin_addr.s_addr, cli_ip_addr,sizeof(cin)) != NULL) {
		printf("Client(%s:%d) connected.\n", cli_ip_addr, ntohs(cin.sin_port));
	} else {
		perror("inet_ntop");

	}
#endif	
	int ret = -1;
	char buf[BUFSIZ];

	
	/* 读写 */
while(1) {	
	bzero(buf,BUFSIZ);
	do {
		
		ret = read(newfd, buf, BUFSIZ-1);
	} while(ret < 0 && EINTR == errno);
	if(ret < 0) { //出错
		perror("read");
	}
	
	if(!ret || !strncasecmp (buf, QUIT_STR, strlen (QUIT_STR))) { /* read 的返回值为0: 表示对方关闭*/
		close(newfd);
		break;
	}

	printf("Receive data: %s\n", buf);
	
}
	
	close(fd);
	return 0;
}
