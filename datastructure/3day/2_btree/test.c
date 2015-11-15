#include "btree.h"

int main(void)
{
	btree_pnode t;

	create_btree(&t);

	printf("先序遍历序列为:\n");
	pre_order(t);
	printf("\n");
	printf("先序非递归遍历序列为:\n");
	pre_order_un(t);
	printf("\n");
	printf("中序遍历序列为:\n");
	mid_order(t);
	printf("\n");
	printf("后序遍历序列为:\n");
	post_order(t);
	printf("\n");
	printf("按层遍历序列为:\n");
	level_order(t);
	printf("\n");
	return 0;
}
