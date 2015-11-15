#include<stdio.h>

void swap(int *x,int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
    return;
}

void taxis(int *z,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	    if(z[i]>z[j])
		swap(z+i,z+j);
    for(i=0;i<n;i++)
	printf("%d ",z[i]);
    printf("\n");
    return;
}

int main(void)
{
    int a[10]={2,1,5,4,3,7,6,9,8,0};
    taxis(a,10);

    return 0;
}
