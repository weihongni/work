#include<stdio.h>

int main(void )
{
	int a;
	printf("Please input a integer!");
	scanf("%d",&a);
	if(a>8)
		printf("8\n");
	else if(a>7)
		printf("7\n");
	else if(a>6)
		printf("6\n");
	else
		printf("else\n");


	return 0;
}
