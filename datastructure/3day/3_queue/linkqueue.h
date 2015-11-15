#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int datatype;
typedef struct listnode{
	datatype data;
	struct listnode *next;
}list_node,*list_pnode;

typedef struct linkqueue
{
	list_pnode front,rear;
}link_queue,*link_pqueue;


extern void init_linkqueue(link_pqueue *Q);
extern void in_linkqueue(link_pqueue q,datatype d);
extern void out_linkqueue(link_pqueue q,datatype *d);
extern bool empty_linkqueue(link_pqueue q);
extern void show_linkqueue(link_pqueue q);

#endif
