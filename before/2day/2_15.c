#include<stdio.h>

int Fibonacci(int a)
{
	if(a<1)
		printf("input error!");
	else if(a==1||a==2)
		return 1;
	else
		return Fibonacci(a-1)+Fibonacci(a-2);
}

int main(void)
{
	int n,b;
	scanf("%d",&n);
	b=Fibonacci(n);
	printf("%d\n",b);

	return 0;
}
