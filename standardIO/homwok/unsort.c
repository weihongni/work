#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int j=-2;
	char ch;
	FILE *fp1,*fp2;
	if(argc != 3){
		printf("Usage: %s <src_filename> <des_filename>\n",argv[0]);
		exit(1);
	}
	if((fp1 = fopen(argv[1],"r"))==NULL){
		perror("fopen");
		exit(1);
	}
	if((fp2 = fopen(argv[2],"w"))==NULL){
		perror("fopen");
		exit(1);
	}

	fseek(fp1,5,SEEK_SET);
	while((ftell(fp1) != 1)){
		fseek(fp1,j,SEEK_END);
		ch = fgetc(fp1);
		putchar(ch);
		usleep(100000);
//		printf("%ld\n",ftell(fp1));
		printf(" ");
		fputc(ch,fp2);
		j--;
	}
	printf("\n");

	fclose(fp1);
	fclose(fp2);

	return 0;
}
