#ifndef __BTREE_H__
#define __BTREE_H__

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char datatype;
typedef struct btreenode{
	datatype data;
	struct btreenode *lchild,*rchild;
}btree_node,*btree_pnode;

#endif
