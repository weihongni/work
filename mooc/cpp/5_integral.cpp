#include<iostream>
#include<cmath>
using namespace std;

double sinx(double x)
{
	return sin(x);
}
double e_sqrx(double x)
{
	return exp(-x*x);
}
double x_sqrx(double x)
{
	return 2*x/(1+x*x);
}

double integral(double a,double b,double (*fun)(double),int n)
{
	double h=(b-a)/n;
	double sum=((*fun)(a)+(*fun)(b))/2;
	for(int i=1;i<n;i++)
		sum+=(*fun)(a+i*h);
	sum*=h;

	return sum;
}

int main(void)
{
	double s=integral(0,3.14159265/2,sinx,1000);
	cout<<"sin(x)="<<s<<endl;
	s=integral(0,1,e_sqrx,1000);
	cout<<"e_sqrx="<<s<<endl;
	s=integral(-1,5,x_sqrx,1000);
	cout<<"x_sqrx="<<s<<endl;

	return 0;
}
