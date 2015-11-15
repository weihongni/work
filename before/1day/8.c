#include<stdio.h>
#define NU 60

int main(void)
{
	int a,b,c;
	printf("请输入分钟数：");
	scanf("%d",&a);
	
	b = a/NU;
	c = a%NU;

	printf("你输入的时间是 %d 小时 %d 分钟！\n", b,c);

	return 0;
}
