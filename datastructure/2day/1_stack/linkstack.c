#include"linkstack.h"

int main(void)
{
	link_pstack top;
	int a,b;
	init_linkstack(&top);
	printf("Please input three ingeters:");
	for(b=0;b<3;b++)
	{
		scanf("%d",&a);
		push_linkstack(&top,a);
	}
	while(!empty_linkstack(top))
	{
		pop_linkstack(&top,&a);
		printf("%d\t",a);
	}
	printf("\n");

	return 0;
}
