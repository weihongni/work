#include<stdio.h>

int num (int x)
{
    if (x > 1)
        return x + num(x-1);
    else
	return 1;
}

int main(void)
{
    int a;
    scanf("%d",&a);
    printf("%d\n",num(a));

    return 0;
}
