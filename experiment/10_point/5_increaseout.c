#include<stdio.h>

int main(void)
{
    int a[10]={1,3,4,5,7},b[10]={0,2,6,8,9};
    int *p1 = a,*p2 =b;
    int i,j,tmp;
    for(i=0;i<5;i++)
	a[i+5] = b[i]; 
    for(i=0;i<9;i++)
    {
	for(j=i+1;j<10;j++)
	{
	    //   *(p1+i)=*(p1+i)<*(p1+j)?*(p1+i):*(p1+j);
	    // b[i]=(a[i]<a[j])?a[i]:a[j];
	    while(a[i]>a[j])
	    {
		tmp = a[j];
		a[j] = a[i];
		a[i] = tmp;
	    }
	}
    }
    for(i=0;i<10;i++)
	printf("%d\t",a[i]);

    return 0;
}
