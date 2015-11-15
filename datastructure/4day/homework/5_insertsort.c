#include<stdio.h>

#define N 6

void insert_sort(int *a);
void show(int *a);

int main(void)
{
	int a[N] = {49,38,65,78,13,27};

	show(a);
	insert_sort(a);

	return 0;
}

void insert_sort(int *a)
{
	int i,j,tmp;

	for(i=1;i<N;i++){
		tmp = a[i];
		for(j=i-1;j>=0;j--){
			if(a[j]<tmp)
				break;
			a[j+1]=a[j];
		}
		a[j+1] = tmp;
		show(a);
		sleep(1);
	}
}

void show(int *a)
{
	int i;
	for(i=0;i<N;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
