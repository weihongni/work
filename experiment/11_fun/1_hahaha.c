#include<stdio.h>

int num(int x,int y)
{
    return x + y;
}

int diff(int x,int y)
{
    return x - y;
}

int product(int x,int y)
{
    return x * y;
}

int main()
{
    int a,b;
    printf("Please input two integer!\n");
    scanf("%d%d",&a,&b);
    printf("%d + %d = %d\n",a,b,num(a,b));
    printf("%d - %d = %d\n",a,b,diff(a,b));
    printf("%d * %d = %d\n",a,b,product(a,b));


    return 0;
}
