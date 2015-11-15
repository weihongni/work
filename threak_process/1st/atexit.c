#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void func1(void)
{
	printf("I'm func1\n");

}

void func2(void)
{
	        printf("I'm func2\n");

}

void func3(void)
{
	        printf("I'm func3\n");

}

int main(void)
{

	printf("atexit() demo\n");
	
	atexit(func1);
	atexit(func2);
	atexit(func3);

	sleep(1);
	printf("after sleep\n");
//	printf("hello world");
	exit(1);

//	return 0;
}
