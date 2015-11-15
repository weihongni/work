
#include<stdio.h>

void fun(float b)
{
	double a;
	a = b * b * b;
	printf("The anser is %f\n",a);
}


int main(void)
{
	float b;

	printf("Please input a float number :\n");
	scanf("%f",&b);
	fun(b);

	return 0;
}
