#include<stdio.h>

char * get_memory(void){
	char p[] = "hello world";
	return p;
}

void Test(void){
	char *str = NULL;
	str = get_memory();
	printf("%s\n",str);
}

int main(void)
{
	Test();

	return 0;
}
