#include<stdio.h>

float fun1(float a,float b)
{
	float c;
	c = a * b;

	return c;
}

float fun2(struct gas *p)
{
	float a;
	a = p[0] * p[1];

	return a;
}

int main(void)
{
	struct gas{
		float distance;
		float gals;
		float mpg;	//mpg = distance * gals	
	};

	struct gas a,*p;
	scanf("%f%f",&a.distance,&a.gals);
	p = &a;
	a.mpg = fun1(a.distance,a.gals);
	printf("%f\n",a.mpg);

	a.mpg = fun2(p);
	printf("%f\n",a.mpg);

	return 0;
}
