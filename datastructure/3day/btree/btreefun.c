#include "btree.h"
#include "linkqueue.h"
#include "seqstack.h"
//输入为#表示该结点不存在,否则存在
#if 1
void create_btree(btree_pnode *T)
{
	datatype_bt ch;
	scanf("%c",&ch);
	if('#' == ch)
		*T = NULL;
	else{
		//创建根结点，同时将数据存储进去
		*T = (btree_pnode)malloc(sizeof(btree_node));
		if(NULL == *T){
			printf("malloc failed!\n");
			exit(1);
		}
		(*T)->data = ch;
		//创建根结点的左子树
		create_btree(&(*T)->lchild);
		//创建根结点的右子树
		create_btree(&(*T)->rchild);
	}
}
#else
btree_pnode create_btre(void)
{
	datatype_bt ch;
	btree_pnode new;
	scanf("%c",&ch);
	if('#' == ch)
		return NULL;
	else{
		//创建根结点，同时将数据存储进去
		new = (btree_pnode)malloc(sizeof(btree_node));
		if(NULL == new){
			printf("malloc failed!\n");
			exit(1);
		}
		new->data = ch;
		//创建根结点的左子树
		new->lchild = create_btre();
		//创建pre根结点的右子树
		new->rchild = create_btre();


	}
}
#endif

//先序遍历
void pre_order(btree_pnode t)
{
	if(t != NULL){
		printf("%c",t->data);
		//先序遍历左子树
		pre_order(t->lchild);
		//先序遍历右子树
		pre_order(t->rchild);
	}
}
//先序遍历非递归算法的实现
void pre_order_un(btree_pnode t)
{
	seq_pstack s;
	
	init_seqsatck(&s);  //初始化一个栈
	while(1){
		if(t != NULL){
			printf("%c",t->data);
			if(t->rchild != NULL)
				push_seqstack(s,t->rchild);
			t = t->lchild;
		}else if(!empty_seqstack(s))
			pop_seqstack(s,&t);
		else
			break;
	}	
}
//中序遍历
void mid_order(btree_pnode t)
{
	if(t != NULL){
		//中序遍历左子树
		mid_order(t->lchild);
		printf("%c",t->data);
		//中序遍历右子树
		mid_order(t->rchild);
	}
}
//后序遍历
void post_order(btree_pnode t)
{
	if(t != NULL){
		//后序遍历左子树
		post_order(t->lchild);
		//后序遍历右子树
		post_order(t->rchild);
		printf("%c",t->data);
	}
}
//按层遍历
void level_order(btree_pnode t)
{
	link_pqueue q;
	init_linkqueue(&q);	//初始化队列
	while(t != NULL){
		printf("%c",t->data);
		if(t->lchild != NULL)
			in_linkqueue(q,t->lchild);
		if(t->rchild != NULL)
			in_linkqueue(q,t->rchild);
		if(!empty_linkqueue(q))
			out_linkqueue(q,&t);
		else
			break;
	}
}
