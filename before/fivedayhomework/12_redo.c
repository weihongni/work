#include<stdio.h>

float my_power(float x,int y)
{
    if (0 == y) 
	return 1.0;
    else if(y>0)
	return x * my_power(x,y-1);
    else
	return 1/x*my_power(x,y+1);
}

int main(void)
{
    int a;
    float b;
    printf("Please input an integer and then enter a float number:");
    scanf("%d%f",&a,&b);
    printf("%.6f\n",my_power(b,a));

    return 0;
}
