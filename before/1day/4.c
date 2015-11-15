#include<stdio.h>
#define YEAR 3.1536e7

int main()
{
    int a;
    double time;
    printf("please input your age:");
    scanf("%d",&a);

    time = YEAR * a;

    printf("恭喜你！你已经活了%f秒！\n",time);

    return 0;
}
