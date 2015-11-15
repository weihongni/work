#include<stdio.h>
#include<math.h>

void transform(double source[],double target[],int n,double (*pfun)(double))
{
    int i;
    for(i=0;i<n;i++)
	target[i]=(*pfun)(source[i])
    for(i=0;i<n;i++)
	printf("%f\t",target[i]);
}

int fun1(int a)
{
    return a*a;
}

int fun2(int b)
{
    return b+b;
}

int main(void)
{
    int n;
    double source[],target[];
    for(n=0;n<100,n++)
	source[n]=random();
    tansform(source,target,100,sin); 
    tansform(source,target,100,cin); 
    tansform(source,target,100,fun1); 
    tansform(source,target,100,fun2); 

    return 0;
}
