//输入3个整数，并从小到大输出；

#include<iostream>
using namespace std;

void swap(int *px,int *py)
{
	int t = *px;
	*px = *py;
	*py = t;
}

int main(void)
{
	int a,b,c;
	cout<<"Please input three integers :"<<endl;
	cin>>a>>b>>c;
	int *pa = &a,*pb = &b,*pc = &c;
	if(*pa > *pb)
		swap(pa,pb);
	else if(*pa > *pc)
		swap(pa,pc);
	else if(*pb > *pc)
		swap(pb,pc);
	cout<<"the sort is :\t"<<a<<"\t"<<b<<"\t"<<c<<endl;

	return 0;
}
