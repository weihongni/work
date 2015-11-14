//使数组中的元素逆置；

#include<iostream>
#include<stdlib.h>
using namespace std;

void invert(double *x,int n)
{
	double t,*i,*j;
	i = x;
	j = x + n -1;
	while(i<j)
	{
		t = *i;
		*i =  *j;
		*j = t;
		i++;
		j--;
	}
}

int main(void)
{
	double *p = new double[15];
	if(NULL==p)
	{
		cout<<"Space application failure!";
		return 1;
	}
	for(int i=0;i<15;i++)
		p[i]=(double)rand()/RAND_MAX*(100-10)+10;// 产生[10,100]的整数，再强制转换类型；
	// /RAND_MAX变换到[0,1],*(100-10)变换到[0,90];
	cout<<"Original array:\n";
	for(int i=0;i<10;i++)
		cout<<p[i]<<" ";
	cout<<endl;
	invert(p,10);
	cout<<"after:\n";
	for(int i=0;i<10;i++)
		cout<<p[i]<<" ";
	cout<<endl;
	delete []p;

	return 0;
}
