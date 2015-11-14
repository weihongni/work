//去掉字符串首部的空格；

#include<iostream>
using namespace std;

char *itrim(char s[])
{
	int k,j;
	k = 0;
	while(s[k] == ' ')
	{
		k++;
	}
	j = k;
	while(s[j] != '\0')
	{
		s[j-k] = s[j];
		j++;
	}
	s[j-k] = '\0';
//	return &s[0];
	return s;
}

int main(void)
{
	char str[100];
	cin.getline(str,99);
	cout<<"before |"<<str<<"|"<<endl;
//	itrim(str);
	cout<<"later |"<<itrim(str)<<"|"<<endl;

	return 0;
}
