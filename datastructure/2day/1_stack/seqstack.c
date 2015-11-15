#include"seqstack.h"

int main(void)
{
	int a,i;
	seq_pstack s;

	init_stack(&s);
	printf("Please input three integers:");
	for(i=0;i<3;i++)
	{
		scanf("%d",&a);
		push_stack(s,a);
	}
	for(i=0;i<3;i++)
	{
		pop_stack(s,&a);
		printf("%d\t",a);
	}
	printf("\n");

	return 0;
}
