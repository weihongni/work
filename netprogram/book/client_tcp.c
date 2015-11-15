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
	int sockfd;
	struct sockaddr_in servaddr;
	char buf[BUFFER_SIZE] = "Hello server";

	if(argc<3){
		printf("Usage : %s <ip> <port>\n",argv[0]);
		exit(-1);
	}
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1){//建立socket连接
		perror("socket");
		exit(-1);
	}

	bzero(&servaddr,sizeof(servaddr));//设置sockaddr_in结构体中相关参数
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);

	if((connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))) == -1){//建立TCP连接
		perror("connect");
		exit(-1);
	}
	send(sockfd,buf,sizeof(buf),0);//发送的数据给服务器端
	if(recv(sockfd,buf,sizeof(buf),0) == -1){
		perror("recv");
		exit(-1);
	}
	printf("recv from server : %s\n",buf);
	close(sockfd);

	return 0;
}
