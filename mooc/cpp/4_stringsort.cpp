#include<iostream>
using namespace std;

void *mystrcpy(char *s1,char *s2)
{
	while(*s2!=0)
		*s1++=*s2++;
	*s1='\0';
}

int mystrcmp(char *s1,char *s2)
{
	while(*s1==*s2 && *s1!=0 && *s2!=0)
	{
		s1++;
		s2++;
	}
	return *s1-*s2;
}

void swap(char *p,char *q)
{
	char t[10];
	mystrcpy(t,p);
	mystrcpy(p,q);
	mystrcpy(q,t);
}

void sort(char (*p)[10],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(mystrcmp(p[j],p[j+1])>0)
				swap(p[j],p[j+1]);
}

void show(char (*s)[10],int n)
{
	int i;
	for(i=0;i<n-1;i++)
		cout<<s[i]<<" ";
	cout<<s[n-1]<<endl;
}

int main(void)
{
	int n;
	cout<<"The number of strings is :";
	cin>>n;
	char(*s)[10]=new char[n][10];
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<' ';
		cin>>s[i];
	}
	sort(s,n);
	cout<<endl;
	show(s,n);
	delete []s;

	return 0;
}
