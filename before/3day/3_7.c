#include<stdio.h>

void fun(int m,int n,int a[m],int b[n])
{
	int i, c[4];
	for(i=0;i<4;i++)
	{
		c[i] = a[i] + b[i];
		printf("%d\t",c[i]);
	}
	printf("\n");
}
	

int main(void)
{
	int a[4]={2,4,6,8},b[4]={1,0,3,6};
	fun(4,4,a,b);

	return 0;
}
