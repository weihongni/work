#include<stdio.h>
#define MIN(x,y) a<b?a:b

int main(void)
{
    int a,b;
    printf("Please input two numbers :");
    scanf("%d%d",&a,&b);
    printf("The minimal is %d\n",MIN(a,b));

    return 0;
}
