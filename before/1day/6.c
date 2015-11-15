#include<stdio.h>

int main(void)
{
    int ch2,ch3,ch4;
    char ch1;
    ch1 = '\r';
    ch2 = '\015';
    ch3 = '\x0D';
    ch4 = 13;
    printf("1%c",ch1);
    printf("2%c",ch2);
    printf("3%c",ch3);
    printf("4%c",ch4);

    return 0;
}
