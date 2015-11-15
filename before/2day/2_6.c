
#include<stdio.h>

int main(void)
{
	int a,b,j;

	printf("Please input a number :\n");
	scanf("%d",&a);
	b = a;
	for(a;a>1;a--){
		for(j=2;j<a;j++){
			if(a%j==0)
				break;
			if((a-1)==j)
				printf("%d ",a);
		}		
	
	}
	if(b == 1)
		printf("1\n");
	if(b > 1)
		printf("2 1\n");
	return 0;
}
