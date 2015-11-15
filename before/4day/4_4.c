#include<stdio.h>

int j=0;
//int fun(int a);

int main(void)
{
	int a,i;
	a = 1;
	for(i=0;i<8;i++)
		a += fun(a);
	printf("The number is :%d\t",j);
	printf("The a = %d\n",a);

	return 0;
}

int fun(int a)
{
	a += a;
	j++;

	return a;
}
