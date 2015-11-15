#include<stdio.h>

int partions(int a[],int low,int high)
{
	int pivotkey=a[low];
	a[0] = a[low];
	while(low<high)
	{
		while(low<high && a[high]>=pivotkey)
			--high;
		a[low] = a[high];
		while(low<high && a[low]<=pivotkey)
			++low;
		a[high] = a[low];
	}
	a[low] = a[0];

	return low;
}

void qsort(int a[],int low,int high)
{
	int pivottag;
	if(low<high)
	{
		pivottag=partions(a,low,high);
		qsort(a,low,pivottag-1);
		qsort(a,pivottag+1,high);
	}
}

void quicksort(int a[],int n)
{
	int i;
	qsort(a,1,n);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

int main(void)
{
	int a[10]={2,3,4,1,5,7,9,0,6,8};
	quicksort(a,10);

	return 0;
}
