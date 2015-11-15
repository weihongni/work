

#include<stdio.h>

void fun(int b)
{
	int a,c;
	a = b / 7;
	c = b % 7;
	
	printf("%d days are %d weeks, %d days\n", b,a,c);
}


int main(void)
{
	int b;

	printf("Please input the days :\n");
	scanf("%d",&b);
	fun(b);

	return 0;
}
