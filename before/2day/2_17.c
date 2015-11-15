#include<stdio.h>

void fun(int a,int b)
{
	int r;
	while(b!=0)
	{	
		r = a%b;
		a = b;
		b = r;
	}
	printf("The greatset common divisor of two numbers for :%d\n",a);

}

int main(void)
{
	int a,b;
	printf("Please input two numbers :");
	scanf("%d%d",&a,&b);
	fun(a,b);

	return 0;
}
