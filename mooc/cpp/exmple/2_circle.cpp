#include<iostream>
using namespace std;

class point{
	private:
		int x,y;
	public:
		void initpoint(int,int);
		int getx(){
			return x;
		}
		int gety(){
			return y;
		}
		void print();
};
void point::initpoint(int a,int b)
{
	x = a;
	y = b;
}
void point::print()
{
	cout<<'['<<x<<","<<y<<']';
}

class circle{
	private:
		double radius;
		point center;
	public:
		void initcircle(double,point);
		double getradius();
		point getcenter();
		double area();
		void print();
};
void circle::initcircle(double r,point p)
{
	radius = (r>=0?r:0);
	center = p;
}
double circle::getradius(){
	return radius;
}
point circle::getcenter(){
	return center;
}
double circle::area(){
	return 3.14159*radius*radius;
}
void circle::print(){
	cout<<"cent = ";
	center.print();
	cout<<";radius = "<<radius<<endl;
}

int main(void)
{
	point p,center;
	p.initpoint(30,50);
	center.initpoint(120,80);
	circle c;
	c.initcircle(10.0,center);

	cout<<"point p: ";
	p.print();
	cout<<endl;
	cout<<"circle c: ";
	c.print();
	cout<<"The center of circle c:";
	c.getcenter().print();
	cout<<"\nThe area of circle c: "<<c.area()<<endl;

	return 0;
}
