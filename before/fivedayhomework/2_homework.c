#include<stdio.h>

int main(void)
{
    struct OO{
	char str[10];
	char str1[10];
	int days;
	int moon;
    };

    struct OO bb = {"october","oct",31,10};
    printf("%s\t%s\t%d\t%d\n",bb.str,bb.str1,bb.days,bb.moon);

    return 0;
}
