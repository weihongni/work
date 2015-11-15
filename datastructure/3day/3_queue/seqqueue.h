#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

typedef int datatype;
typedef struct seqqueue{
	datatype data[SIZE];
	int front,rear;
}seq_queue,*seq_pqueue;

extern void init_seqqueue(seq_pqueue *Q);
extern void in_seqqueue(seq_pqueue q,datatype d);
extern void out_seqqueue(seq_pqueue q,datatype *d);
extern bool empty_seqqueue(seq_pqueue q);
extern void show_seqqueue(seq_pqueue q);
extern bool full_seqqueue(seq_pqueue q);

#endif
