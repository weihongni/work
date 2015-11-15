#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>

#define N 15
#define p 17

typedef int datatype;
typedef struct list{
	datatype data;
	struct list *next;
}link_list,link_plist;

typedef struct hash{
	link_plist *h;
	int length;
}hash_tbl,*hash_ptbl;

void show_hash_link(hash_ptbl hp);
link_plist search_hash_link(int key,hash_ptbl hp);
void create_hash_link(int n,datatype *a,hash_ptbl hp);
void init_hash_link(int m,hash_ptbl *H);

int main(void)
{
	datatype a[N] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
	hash_ptbl hp;
	int sno;
	link_plist ret;
	char ch;

	init_hash_link(p,&hp);
	create_hash_link(N,a,hp);
	while(1){
		printf("Please input the key!");
		scanf("%d",&sno);
		ret = search_hash_link(sno,hp);
		if(ret == NULL)
			printf("No data to find!");
		else
			printf("The record is: %d\n",ret->data);
		printf("Do you want to continue(Y/N)?\n");
		getchar();
		scanf("%c",&ch);
		if((ch == 'Y')||(ch =='y'))
			continue;
		else
			break;
	}

	return 0;
}

void init_hash_link(int m,hash_ptbl *H)
{
	int i;
	*H = (hash_ptbl)malloc(sizeof(hash_tbl));
	if(NULL == *H){
		perror("malloc");
	exit(-1);
	}
	for(i=0;i<m;i++)
		(*H)->h[i] = NULL;
}

void create_hash_link(int n,datatype *a,hash_ptbl hp)
{
	int i;
	int hash_val;
	link_plist new;
	for(i=0;i<n;i++){
		hash_val = a[i]%p;
		new = (link_plist)malloc(sizeof(link_list));
		if(NULL == new){
			perror("malloc");
			exit(-1);
		}
		new->data = a[i];
		new->next = hp->h[hash_val];
		hp->h[hash_val] = new;
		show_hash_link(hp);
		sleep(1);
	}
}

link_plist search_hash_link(int key,hash_ptbl hp)
{
	int hash_val;
	link_plist q;
	hash_val = key%p;
	q = hp->h[hash_val];
	while(q != NULL){
		if(q->data == key)
			return q;
		q = q->next;
	}
	return NULL;
}

void show_hash_link(hash_ptbl hp)
{
	int i;
	link_plist q;
	for(i=0;i<hp->length;i++){
		q = hp->h[i];
		printf("hp->h[%02d]",i);
		if(NULL != q)
			printf("%p",hp->h[i]);
		while(NULL != q){
			printf("--->%02d",q->data);
			q = q->next;
		}
		printf("\n");
	}
	printf("******************************\n");
}
