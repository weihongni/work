#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10
typedef int datatype;

typedef struct sqestack{
	datatype data[SIZE];
	int top;
}seq_stack,*seq_pstack;

extern void init_stack(seq_pstack *s);
extern void push_stack(seq_pstack s,datatype b);
extern void pop_stack(seq_pstack s,datatype *b);
extern bool empty_seqstack(seq_pstack s);
extern bool full_seqstack(seq_pstack s);
extern void show_seqstack(seq_pstack s);

#endif
