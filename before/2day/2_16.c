#include<stdio.h>

void fun(int a)
{
	int i,b;
	for(;a;){
		b = a % 8;
		a = a / 8;
		printf("%d",b);
	}
	printf("\n");

}

int main(void)
{
	int a;
	scanf("%d",&a);
	fun(a);

	return 0;
}
