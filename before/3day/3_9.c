#include<stdio.h>

int main()
{
	int i,N=6,a[N],max = 0;
	printf("Please input a group numbers :");
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N-1;i++) 
			max = (max > a[i] + a[i+1]) ? max : a[i] + a[i+1];
	printf("The maximal num is : %d\n",max);

	return 0;
}
