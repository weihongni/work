//通过函数指针来调用其他函数，返回一个周长和面积；

#include<iostream>
using namespace std;

double length(double r)
{
	return 2*3.1415926*r;
}

double area(double r)
{
	return 3.14159265*r*r;
}

double function(double (*f)(double),double x)
{
	return (*f)(x);
}

int main(void)
{
	double r;
	cout<<"The radius of a circle is :\t";
	cin>>r;
	cout<<"The area of a circle is :\t"<<function(area,r)<<endl;
	cout<<"The length of a circle is :\t"<<function(length,r)<<endl;

	return 0;
}
