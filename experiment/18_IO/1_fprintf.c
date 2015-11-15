#include<stdio.h>

int main(void)
{
	int i=0;
	for(i=0;i<399;i++){
		if(i>=100)
			fprintf(stdout,"%d ",i);
		else if(i>=10)
			fprintf(stdout,"0%d ",i);
		else if(i>=0)
			fprintf(stdout,"00%d ",i);
	}
	while(1);

	return 0;
}
