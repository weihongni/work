
#include<stdio.h>

int main(void)
{
	int a,b,i;
	printf("请输入一个整数：");
	scanf("%d",&a);
	
	b = a;
	for(i=0;i<10;i++)
	{
		b += i;
	//	printf("%d\n", b);
		printf("%d\t", b);
	//	printf("%d ", b);
	}


	return 0;
}
