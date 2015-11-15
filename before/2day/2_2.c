#include<stdio.h>

int main(void)
{
	int a = 12;
	int n = 5;

	a += a;
	printf("a = %d\n",a);
	a -= 2;
	printf("a = %d\n",a);
	a *= 2 + 3;
	printf("a = %d\n",a);
	a /= a + a;
	printf("a = %d\n",a);
	a %= (n%2);
	printf("a = %d\n",a);
	a += a -= a *= a;
	printf("a = %d\n",a);

	return 0;
}
