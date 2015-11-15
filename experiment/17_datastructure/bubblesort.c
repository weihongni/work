#include<stdio.h>

void BubbleSort(LineList R[],int n)
{
    int i,j,exchange;
    LineList tmp;
    for(i=0;i<n-1;i++)
    {
	exchange=0;
	for(i=n-1;j>i;j--)
	    if(R[j].key<R[j-1],key)
	    {
		tmp = R[j];
		R[j] = R[j-1];
		R[j-1] = tmp;
		exchange =1;
	    }
	if(exchange==0)
	    return;
    }
}

int main(void)
{
    

    return 0;
}
