#include"seqstack.h"

void init_stack(seq_pstack *s)
{
	*s = (seq_pstack)malloc(sizeof(seq_stack));
	if(NULL == *s)
	{
		printf("space request failed!");
		exit(1);
	}
	(*s)->top = -1;
}

void push_stack(seq_pstack s,datatype b)
{
	if(full_seqstack(s))
	{
		printf("stack full!\n");
		return;
	}
	s->top++;
	s->data[s->top] = b;
	show_seqstack(s);
}

void pop_stack(seq_pstack s,datatype *b)
{
	if(empty_seqstack(s))
	{
		printf("stack empty!\n");
		return;
	}
	*b = s->data[s->top];
	s->top--;
}

bool empty_seqstack(seq_pstack s)
{
	if(s->top == -1)
		return true;
	else
		return false;
}

bool full_seqstack(seq_pstack s)
{
	if(s->top == SIZE-1)
		return true;
	else
		return false;
}	

void show_seqstack(seq_pstack s)
{
	int i;
	for(i=0;i<=s->top;i++)
		printf("%d\t",s->data[i]);
	printf("\n");
}
