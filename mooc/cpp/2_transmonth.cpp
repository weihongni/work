#include<iostream>
using namespace std;

char *month_name(int n)
{
	static char *month[]={"Illegal","January","February","March","April","May","June","July","August","September","October","November","December"};
	return (n>=1 && n<=12)?month[n]:month[0];
}

int main(void)
{
	int n;
	cin>>n;
	cout<<n<<"-"<<month_name(n)<<endl;

	return 0;
}
