#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(void)
{
	int a = 1;
	char ch,h[1000];
	time_t t,re;
	struct tm *sp;
	FILE *fp;
	fp = fopen("test.txt","a+")
	if(NULL==fp){
		perror("fopen");
		exit(1);
	}
//	ch = fgetc(fp);
//	if(ch==EOF)
//		printf("11\n");
	while(fgets(h,1000,fp) != NULL)
		a++;
	while(1){
		re = time(&t);
		sp = localtime(&t);
		printf("%d %d-%d-%d %d:%d:%d\n",a,sp->tm_year+1900,sp->tm_mon+1,sp->tm_mday,sp->tm_hour,sp->tm_min,sp->tm_sec);
		fprintf(fp,"%d %d-%d-%d %d:%d:%d\n",a,sp->tm_year+1900,sp->tm_mon+1,sp->tm_mday,sp->tm_hour,sp->tm_min,sp->tm_sec);
		fflush(fp);
		a++;
		sleep(1);
	}

	return 0;
}
