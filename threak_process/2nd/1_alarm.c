#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void alarm_handler(int signo)
{
	printf("Receive a SIGALRM signal\n");
}

int main(void)
{
	int ret;
	printf("Before alarm\n");
	signal(SIGALRM,alarm_handler);
	ret = alarm(5);
	pause();
	printf("I have been waken up.\n",ret);

	return 0;
}
