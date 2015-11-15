#include<stdio.h>
#include<string.h>

int is_within(char x,char *y)
{   
    int j;
    for(j=0;j<strlen(y);j++)
    {
	if(x==y[j])
	    return 1;
    }
    return 0;
}

int main(void)
{   
    int i;
    char a[]="asfegfv",b[]="asflfieal";
    char *pb = b;
    for(i=0;i<strlen(a);i++)
    {
	printf("%c\t%d\n",a[i],is_within(a[i],pb));
    }

    return 0;
}
