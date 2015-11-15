#include"seqqueue.h"

void init_seqqueue(seq_pqueue *Q)
{
	*Q = (seq_pqueue)malloc(sizeof(seq_queue));
	if(NULL == *Q){
		printf("mallco failed!\n");
		exit(1);
	}
	(*Q)->front = (*Q)->rear = SIZE-1;
}

void in_seqqueue(seq_pqueue q,datatype d)
{
	if(full_seqqueue(q)){
		printf("queue full!\n");
		return;
	}

	q->rear = (q->rear+1)%SIZE;
	q->data[q->rear] = d;
}

void out_seqqueue(seq_pqueue q,datatype *d)
{
	if(empty_seqqueue(q)){
		printf("stack is empty\n");
		return;
	}
	q->front = (q->front+1)%SIZE;
	*d = q->data[q->front];
}

bool empty_seqqueue(seq_pqueue q)
{
	if(q->front == q->rear)
		return true;
	else
		return false;
}

bool full_seqqueue(seq_pqueue q)
{
	if(q->front == (q->rear+1)%SIZE)
		return true;
	else
		return false;
}

void show_seqqueue(seq_pqueue q)
{
	int i;
	for(i=(q->front+1)%SIZE;i!=(q->rear+1)%SIZE;i=(i+1)%SIZE)
		printf("%d\t",q->data[i]);
	printf("\n");
}
