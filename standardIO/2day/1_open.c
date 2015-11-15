#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	int fd;
	if(argc != 2){
		fprintf(stderr,"Usage:%s <filename>\n",argv[0]);
		exit(1);
	}
	if((fd=open(argv[1],O_RDONLY|O_CREAT|O_EXCL,0644))<0){
		if(errno == EEXTST)
			fd = open(argv[1],O_WRONLY);
		perror("open");
		exit(1);
	}
	close(fd);
//	fopen("1.txt","r");
//	perror("fopen");
//	fprintf(stderr,"fopen:%s\n",strerror(errno));

	return 0;
}
