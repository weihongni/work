#include"btree.h"

#if 1
void create_btree(btree_pnode *T)
{
	datatype ch;
	scanf("%c",&ch);
	if('#' == ch)
		*T = NULL;
	else
	{
		*T = (btree_pnode)malloc(sizeof(btree_node));
		if(NULL == *T)
		{
			printf("malloce falied!\n");
			exit(1);
		}
		(*T)->data = ch;
		create_btree(&(*T)->lchild);
		create_btree(&(*T)->rchild);
	}

}

#else

btree_pnode creade_tree(void)
{
	datatype ch;
	btree_pnode new;
	scanf("%c",&ch);
	if('#' == ch)
		return NULL;
	else
	{
		new = (btree_pnode)malloc(sizeof(btree_node));
		if(NULL == new)
		{
			printf("malloc failed!\n");
			exit(1);
		}
		new->data = ch;
		new->lchild = create_btree();
		new->rchild = create_btree();
	}

}
#endif
