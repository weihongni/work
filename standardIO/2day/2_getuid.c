#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
	uid_t uid;
	uid = getuid();
	printf("uid = %d\n",uid);

	return 0;
}
