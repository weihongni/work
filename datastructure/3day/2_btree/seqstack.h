#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

#define SIZE 10

typedef btree_pnode datatype;
typedef struct seqstack{
	datatype data[SIZE];
	int top;
}seq_stack,*seq_pstack;

extern void init_seqsatck(seq_pstack *S);
extern  void push_seqstack(seq_pstack s,datatype d);
extern void pop_seqstack(seq_pstack s,datatype *d);
extern bool empty_seqstack(seq_pstack s);
extern bool full_seqstack(seq_pstack s);
//extern void show_seqstack(seq_pstack s);
#endif
