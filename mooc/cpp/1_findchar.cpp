#include<iostream>
using namespace std;

char*strchr(char*str,char c)
{
	while(*str!='\0')
	{
		if(*str==c)
			return str;
		str++;
	}
	return NULL;
}

int main(void)
{
	char str[]="abcdefghij";
	char *p;
	p=strchr(str,'j');
	if(p==NULL)
		cout<<"字符串中无该字符！"<<endl;
	else
		cout<<"该字符在串中的位置是： "<<p-str<<endl;

	return 0;
}
