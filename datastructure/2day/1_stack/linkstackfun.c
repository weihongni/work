#include"linkstack.h"

void init_linkstack(link_pstack *T)
{
	*T = NULL;
}

void push_linkstack(link_pstack *T,datatype a)
{
	link_pstack new;
	new = (link_pstack)malloc(sizeof(link_stack));
	if(NULL == new)
	{
		printf("malloc failed!\n");
		exit(1);
	}
	new->data = a;
	new->next = *T;
	*T = new;
}

void pop_linkstack(link_pstack *T,datatype *a)
{
	link_pstack q;
	if(empty_linkstack(*T))
	{
		printf("stack empty!\n");
		return;
	}
	*a = (*T)->data;
	q = *T;
	(*T) = (*T)->next;
	free(q);
}

bool empty_linkstack(link_pstack top)
{
	if(top == NULL)
		return true;
	else
		return false;
}

