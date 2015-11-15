#include<stdio.h>

int main(void)
{
	int a,b;
	a = 0;

	for(a;a<5;a++){
		for(b=0;b<=a;b++)
			printf("%c",'$');
		printf("\n");
	}

	return 0;
}
