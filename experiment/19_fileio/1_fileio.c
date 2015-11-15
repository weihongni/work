#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

#define maxsize 256

int main(int argc,char *argv[])
{
	int fd1,fd2;
	char buff[maxsize];
	int i;
	if(argc != 3){
		printf("command error!\n");
		exit(1);
	}
	fd1 = open(argv[1],O_RDONLY);
	if(fd1 == -1){
		printf("file %s cannot open",argv[1]);
		exit(1);
	}
	if(fd2=open(argv[2],O_WRONLY|O_CREAT|O_APPEND)==-1){
		printf("cannot creat file %s",argv[2]);
		exit(1);
	}

	while(1){
		i = read(fd1,buff,maxsize);
		printf("%d\n",i);
		write(fd2,buff,i);
		if(i==maxsize)
			break;
	}
	close(fd1);
	close(fd2);

	return 0;
}
