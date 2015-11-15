#include<stdio.h>

int main(void)
{
	char a = 127;
	int b = 4;
	int c = a + b;
	a += b;
	printf("c = %d\n",c);
	printf("a = %d\n",a);

	return 0;
}
