#include<stdio.h>

int main(void)
{
    int t,i,s[8]={1,2,3,4,5,6,7,8};
    int *p;
    p = s;
    for(i=0;i<4;i++)
    {
	t = *(p+i);
	*(p+i) = *(p+8-i-1);
	*(p+8-i-1) = t;
    }
    for(i=0;i<8;i++)
	printf("%d%c",*(p+i),' ');
    printf("\n");

    return 0;
}
