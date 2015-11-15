#include"linkstack.h"

void init_linkstack(link_pstack *T)
{
	*T = NULL;
}

void push_linkstack(link_pstack *T,datatype b)
{
	link_pstack new;
	new = (link_pstack)malloc(sizeof(link_stack));
	if(NULL == new)
	{
		printf("malloc failed!\n");
		exit(1);
	}
	new->data = b;
	*T = new;
}

void pop_linkstack(link_pstack *T,datatype *b)
{
	link_pstack q;
	if(empty_linkstack(*T))
	{
		printf("stack empty!");
		return;
	}
	*b = (*T)->data;
	q = *T;
	(*T) = (*T)->next;
	free(q);
}

bool empty_linkstack(link_pstack top)
{
	if(NULL == top)
		return true;
	else
		return false;
}

void show_linkstack(link_pstack top)
{
	for(;top!=NULL;top=top->next)
		printf("%d\t",top->data);
	printf("\n");
}
