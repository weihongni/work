
#include<stdio.h>
#define M 3.0e-23

int main()
{
	int a;
	double nu;
	printf("请输入水的夸脱数：");
	scanf("%d",&a);

	nu = 950*a/M;

	printf("你输入的水中包含的水分子有：%e个\n",nu);

	return 0;
}
