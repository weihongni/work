#include "linkqueue.h"

void init_linkqueue(link_pqueue *Q)
{
	*Q = (link_pqueue)malloc(sizeof(link_queue));
	if(NULL == *Q){
		printf("malloc failed!\n");
		exit(1);
	}
	(*Q)->front = (list_pnode)malloc(sizeof(list_node));
	if(NULL == (*Q)->front){
		printf("malloc failed!\n");
		exit(1);
	}
	(*Q)->front->next = NULL;
	(*Q)->rear = (*Q)->front;
}

void in_linkqueue(link_pqueue q,datatype_lq d)
{
	list_pnode new;
	new = (list_pnode)malloc(sizeof(list_node));
	if(NULL == new){
		printf("malloc failed!\n");
		exit(1);
	}
	new->data = d;

	new->next = q->rear->next;
	q->rear->next = new;
	q->rear = q->rear->next;
}
void out_linkqueue(link_pqueue q,datatype_lq *d)
{
	list_pnode p;
	if(empty_linkqueue(q)){
		printf("队列已空!\n");
		return ;
	}
	p = q->front;
	q->front = q->front->next;
	*d = q->front->data;
	free(p);
}

bool empty_linkqueue(link_pqueue q)
{
	if(q->front == q->rear)
		return true;
	else
		return false;
}
#if 0
void show_linkqueue(link_pqueue q)
{
	list_pnode p;
	for(p = q->front->next;p!=NULL;p = p->next)
		printf("%d\t",p->data);
	printf("\n");
}
#endif
