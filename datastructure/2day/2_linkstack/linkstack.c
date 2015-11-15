#include"linkstack.h"

int main(void)
{
	int a;
	link_pstack top;
	                            
	init_linkstack(&top);

	printf("Please input a decimal number:");
	scanf("%d",&a);
	if(a < 0)
		a = -a;
	while(a != 0)
	{
		push_linkstack(&top,a%8);
		a /= 8;
	}
	if(a < 0)
		printf("-0");
	else
		printf("0");
	while(!empty_linkstack(top))
	{
		pop_linkstack(&top,&a);
		printf("%d",a);
	}
	printf("\n");

	return 0;
}
