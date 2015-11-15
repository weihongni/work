#include<stdio.h>

int main(void)
{
	float c,f;
	printf("Please input the huashi wendu :");
	scanf("%f",&f);
	
	c = 5*(f-32)/9;

	printf("The anser is : %.2f\n",c);

	return 0;
}
