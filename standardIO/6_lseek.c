#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int fd;
	int ret;

	if(argc != 2){
		fprintf(stderr,"Usage:%s <filename>\n",argv[0]);
		exit(1);
	}
	//打开文件
	if((fd = open(argv[1],O_WRONLY|O_CREAT,0644)) < 0){
		perror("open");
		exit(1);
	}

	//修改文件位移量
	if((ret = lseek(fd,1024,SEEK_END)) < 0){
		perror("lseek");
		printf("ret = %d\n",ret);
	}
	
	//写入标志
	write(fd,"e",2);

	//关闭文件
	close(fd);
	return 0;
}
