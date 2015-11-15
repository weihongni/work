

#include<stdio.h>

int main(void)
{
	float a;
	printf("Please input a float number: ");
	scanf("%f",&a);
	
	printf("The input is %.2f or %.2e\n",a,a);

	return 0;
}
