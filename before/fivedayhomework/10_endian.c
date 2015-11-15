#include<stdio.h>

int endian(void)
{
    unsigned int x = 0x12345678;
    unsigned char y = *(char*)&x;
    printf("%x\n",y);
    if(0x12 == y)
	return 0;
    else
	return 1;
}

int main(void)
{
    int n;
    n = endian();
    if(1 == n)
	printf("It is little-endian!\n");
    else
	printf("It is big-endian!\n");

    return 0;
}
