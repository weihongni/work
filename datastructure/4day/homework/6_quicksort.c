#include<stdio.h>

#define N 6

void quick_sort(int low,int high,int *a);
int quick_pass(int i,int j,int *a);
void show(int *a);

int main(void)
{
	int a[N] = {49,38,65,78,13,27};

	show(a);
	quick_sort(0,N-1,a);
	show(a);

	return 0;
}
#if 0
void quick_sort(int low,int high,int *a)
{
	int mid,tmp;
	tmp = a[low];
	while(low<high){
		while(low<high && a[high]>=tmp)
			high--;
		if(low<high)
			a[low] = a[high];
		while(low<high && a[low]<tmp)
			low++;
		if(low<high)
			a[high] = a[low];
	}
	a[low] = tmp;
	mid = low;

	if(low<high){
		show(a);
		quick_sort(low,mid-1,a);
		quick_sort(mid+1,high,a);
	}
}
#endif
int quick_pass(int i,int j,int *a)
{
	int tmp;
	tmp = a[i];
	while(i<j){
		while(i<j && a[j]>=tmp)
			j--;
		if(i<j)
			a[i] = a[j];
		while(i<j && a[i]<tmp)
			i++;
		if(i<j)
			a[j] = a[i];
	}
	a[i] = tmp;
	return i;
}

void quick_sort(int low,int high,int *a)
{
	int mid;
	if(low<high){
		sleep(1);
		mid = quick_pass(low,high,a);
		show(a);
		quick_sort(low,mid-1,a);
		quick_sort(mid+1,high,a);
	}
}

void show(int *a)
{
	int i;
	for(i=0;i<N;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
