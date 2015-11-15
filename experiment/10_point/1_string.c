#include<stdio.h>
#include<string.h>

int main(void)
{
    int i;
    char str[]="Computer Science";
    char *p = str;
    for(i=0;i<strlen(str);i++)
    {
	printf("%c%c",*(p+i),' ');
    }
    printf("\n");

    return 0;
}
