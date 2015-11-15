#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define BUFFER_SIZE 128

int main(int argc,char *argv[])
{
	int listenfd,connfd;
	struct sockaddr_in servaddr,cliaddr;
	socklen_t peerlen;
	char buf[BUFFER_SIZE];

	if(argc<3){
		printf("Usage : %s <ip> <port>\n",argv[0]);
		exit(-1);
	}
	if((listenfd = socket(AF_INET,SOCK_STREAM,0))==-1){//建立socket连接
		perror("socket");
		exit(-1);
	}
	printf("listenfd = %d\n",listenfd);

	bzero(&servaddr,sizeof(servaddr));//设置sockaddr_in结构体中相关参数
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);

	if(bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0){//绑定函数bind()
		perror("bind");
		exit(-1);
	}
	printf("bind success!\n");

	if(listen(listenfd,10)==-1){//调用listen()函数，设置监听模式
		perror("listen");
		exit(-1);
	}
	printf("listening...\n");

	peerlen = sizeof(cliaddr);
	while(1){
		if((connfd=accept(listenfd,(struct sockaddr *)&cliaddr,&peerlen))<0){//等待客户端连接
			perror("accept");
			exit(-1);
		}
		memset(buf,0,sizeof(buf));
		if(recv(connfd,buf,BUFFER_SIZE,0) == -1){//接收客户端发送的数据
			perror("recv");
			exit(-1);
		}
		printf("Received a message: %s\n",buf);
		strcpy(buf,"Welcome to server");
		send(connfd,buf,BUFFER_SIZE,0);
		close(connfd);
	}
	close(listenfd);

	return 0;
}
