
#include<stdio.h>

float my_power(float a,int b)
{
	float n;
	n = 1;
	if (b > 0)
		for(b;b;b--){
			n *= a;
		}
	else
		for(b;b;b++){
			n *= (1/a);
		}

	return n;
}

int main(void)
{
	int b;
	float a,c;
	
	printf("Please input a float nubmer and a int number :\n");
	scanf("%f%d",&a,&b);
	c = my_power(a,b);

	printf("The anser is : %.6f\n",c);

	return 0;
}
