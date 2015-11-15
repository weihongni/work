#include"doublelinklist.h"

void init_doublelist(double_plist *h)
{
	*h = (double_plist)malloc(sizeof(double_list));
	if(NULL == *h){
		printf("malloc failed\n");
		exit(1);
	}
	(*h)->next = (*h)->prior = *h;
}

void create_doublelist(double_plist h)
{
	int n,i;
	double_plist new;
	printf("Please input data's number:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new = (double_plist)malloc(sizeof(double_list));
		if(NULL == new){
			printf("malloc failed\n");
			exit(1);
		}
		scanf("%d",&new->data);
		new->prior = h->prior;
		h->prior->next = new;
		new->next = h;
		h->prior = new;
	}
}

void sort_doublelist(double_plist h)
{
	double_plist q,p;
	p = h->prior;
	while(p != h)
	{
		if(p->data%2 == 0)
		{
			q = p;
			p = p->prior;
			q->prior->next = q->next;
			q->next->prior = q->prior;
			q->prior = h->prior;
			h->prior->next = q;
			q->next = h;
			h->prior =q;
		}
		else
			p = p->prior;
	}
}

void show_doublelist(double_plist h)
{
	double_plist p;
	for(p=h->next;p != h;p=p->next)
		printf("%d\t",p->data);
	printf("\n");
}
