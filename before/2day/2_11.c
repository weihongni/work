#include<stdio.h>

void fun(int a,int b,int c)
{
	int mid,max;
	mid = (a>b)?a:b;
	max = (mid>c)?mid:c;
	printf("The max number is : %d\n",max);
}

int main(void)
{
	int a,b,c;
	printf("Please input 3 nubmer:\n");
	scanf("%d%d%d",&a,&b,&c);
	fun(a,b,c);

	return 0;
}
