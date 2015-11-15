#include<stdio.h>
#include<stddef.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>

int main(void)
{
	DIR *dp;
	struct dirent *ep;
	struct stat st;
	char dirp[50];
	printf("Please input a dir name:\n");
	scanf("%s",&dirp);
	dp = opendir(dirp);
	printf("filename:");
	if(dp!=NULL){
		while(ep=readdir(dp)){
			if(ep->d_name[0]!='.'){
				if(stat(ep->d_name,&st)!=-1){
					printf("%s\t",ep->d_name);
					if((st.st_monde&S_IFMT)==S_IFDIR)		//判断文件的类型
						printf("Directory\t");
					else if((st.st_mode&S_IFMT)==S_IFBLK)		//块文件
						printf("Block special file\t");
					else if((st.st_mode&S_IFMT)==s_IFCHR)		//特殊字符文件
						printf("character special file\t");
					else if((st.st_mode&S_IFMT)==s_IFREG)		//普通文件
						printf("Ordinary file\t");
					else if((st.st_mode&S_IFMT)==s_IFIFO)		//管道文件
						printf("pipefile file\t");
					printf("%o\t",st.st_mode&0x1ff);
					printf("%15s\t",ctime(st.st_atime));
					printf("%15s\t",ctime(st.st_mtime));
					printf("%ld\n",st.st_size);
				}
			}
		}
		cosedir(dp);
	}
	else
		puts("Couldn't open the directory.\n");

	return 0;
}
