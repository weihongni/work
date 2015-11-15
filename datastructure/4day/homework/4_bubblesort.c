#include<stdio.h>

#define N 6

void bubble_sort(int *a);
void show(int *a);

int main(void)
{
	int a[N] = {49,38,65,78,13,27};

	show(a);
	bubble_sort(a);
	show(a);

	return 0;
}

void bubble_sort(int *a)
{
	int i,j,tmp,flag;

	for(i=0;i<N-1;i++){
		flag = 0;
		for(j=0;j<N-1-i;j++)
			if(a[j]>a[j+1]){
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				flag = 1;
				show(a);
				sleep(1);
			}
		if(flag == 0)
			break;
	}
}

void show(int *a)
{
	int i;
	for(i=0;i<N;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
