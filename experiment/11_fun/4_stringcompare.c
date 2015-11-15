#include<stdio.h>

int strcomp(char *x,char*y)
{
    int i;
    for(i=0;(x[i]!='\0')&&(y[i]!='\0');i++)
    {
	if(x[i]==y[i])
	    continue;
	else if(x[i]-y[i]>0)
	    return 1;
	else
	    return -1;
    }
    if(x[i]=='\0'&&y[i]=='\0')
	return 0;
    else if(x[i]=='\0'&&y[i]!='\0')
	return -1;
    else
	return 1;
}

int main(void)
{
    char a[]="abegl",b[]="abfde";
    char *pa = a,*pb = b;
    puts(pa);
    puts(pb);
    printf("%d\n",strcomp(pa,pb));

    return 0;
}
