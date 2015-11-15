#include<stdio.h>

int main(void)
{
    int i,j,n,t,s[]={1,2,3,4,5,6,7,8,9};
    int *p=s;
    printf("Please input a number(1<=n<=9):");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	t=s[8];
	for(j=7;j>=0;j--)
	    s[j+1]=s[j];
	s[0]=t;
    }
    for(i=0;i<9;i++)
	printf("%d\t",p[i]);
    printf("\n");

    return 0;
}
