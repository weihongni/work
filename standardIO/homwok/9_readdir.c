#include<stdio.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>

int main(int argc,char *argv[])
{
	struct stat st;
	struct tm *pt;
	if(argc != 2){
		fprintf(stderr,"Usage:%s <dirname>\n",argv[0]);
		exit(1);
	}
	DIR * pd;
	struct dirent *dir;
	pd = opendir(argv[1]);
	while((dir = readdir(pd)) != NULL){

		if(lstat(dir->d_name,&st)<0){
			perror("lstat");
			exit(1);
		}
		if(S_ISREG(st.st_mode))		//判断文件类型
			printf("-");
		else if(S_ISDIR(st.st_mode))
			printf("d");
		else if(S_ISCHR(st.st_mode))
			printf("c");
		else if(S_ISBLK(st.st_mode))
			printf("b");
		else if(S_ISFIFO(st.st_mode))
			printf("p");
		else if(S_ISSOCK(st.st_mode))
			printf("s");
		else if(S_ISLNK(st.st_mode))
			printf("l");

		int i;				//获取文件权限
		char str[] = "xwr-";
		for(i = 8; i >= 0; i--)
			if(st.st_mode & 1<<i)
				printf("%c",str[i%3]);
			else
				printf("%c",str[3]);
		printf(" %u ",st.st_nlink);	
		printf("%s ",getpwuid(st.st_uid)->pw_name);	
		printf("%s ",getgrgid(st.st_gid)->gr_name);	
		printf("%5ld ",st.st_size);	
		pt = localtime(&st.st_atime);
		printf("%02d-%02d %02d:%02d ",pt->tm_mon+1,pt->tm_mday,pt->tm_hour,pt->tm_min);
		printf("%s\n",dir->d_name);
	}

	return 0;
}

