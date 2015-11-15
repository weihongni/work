#include<stdio.h>

#define N 15

void show(int *a);
int binsearch(int *a,int key);

int main(void)
{
	int a[N] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
	int key,b,c;
	show(a);
	while(1){
		printf("Please input the key!");
		c = scanf("%d",&key);
		if(1 != c)
			return 0;
		b = binsearch(a,key);
		if(-1 != b)
			printf("The %d location is %d\n",key,b);
	}

	return 0;
}

int binsearch(int *a,int key)
{
	int low,high,mid,i;
	for(low=0,high=N-1;low<=high;){
		mid = (low+high)/2;
		if(key == a[mid])
			return mid;
		else if(key < a[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	for(i=N-1;i>=0;i--)
		if(key > a[i])
		{
			printf("The %d between %d and %d !\n",key,a[i],a[i+1]);
			return -1;
		}

}

void show(int *a)
{
	int i;
	for(i=0;i<N;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
