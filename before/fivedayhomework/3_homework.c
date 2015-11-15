#include<stdio.h>

int main(void)
{
	struct animals{
		char dog;
		unsigned long cat;
		unsigned short pig;
		char fox;
	};

	struct animals aa;
	printf("%d\n",sizeof(aa));

	return 0;
}
