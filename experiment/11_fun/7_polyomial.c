#include<stdio.h>

float p(int a,float b)
{
    float val;
    if(0==a)
	val = 1;
    else if(1==a)
	val = b;
    else
	val = (2*a-1)*b*p(a-1,b)-(a-1)*p(a-2,b)/a;

    return val;
}

int main(void)
{
    int n;
    float x,val;
    printf("Please input x and n :");
    scanf("%f%d",&x,&n);
    if(n<0)
	printf("The n should is a positive integer!");
    val = p(n,x);
    printf("The result is %.6f\n",val);

    return 0;
}
