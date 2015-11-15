#include "seqstack.h"

void init_seqsatck(seq_pstack *S)
{
	*S = (seq_pstack)malloc(sizeof(seq_stack));
	if(NULL == *S){
		printf("malloc failed!\n");
		exit(1);
	}

	(*S)->top = -1;
}

void push_seqstack(seq_pstack s,datatype d)
{
	if(full_seqstack(s)){
		printf("栈已满!\n");
		return ;
	}
	s->top++;
	s->data[s->top] = d;
}
void pop_seqstack(seq_pstack s,datatype *d)
{
	if(empty_seqstack(s)){
		printf("栈已空!\n");
		return ;
	}
	*d = s->data[s->top];
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
#if 0
void show_seqstack(seq_pstack s)
{
	int i;
	for(i = 0; i <= s->top; i++)
		printf("%d\t",s->data[i]);
	printf("\n");
}
#endif
