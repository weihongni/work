#include<stdio.h>

int main(void)
{
	int i =1;
	float n;
	printf("wantch out! Here come a bunch of fraction!\n");
	while(i<30){
		n=1/i;
		printf("%f",n);
	}

	printf("That's all,folks!\n");
	return 0;
}
