#include "btree.h"

int main(void)
{
	btree_pnode t;

	create_btree(&t);

	travel("先序遍历序列为:",pre_order,t);
	travel("先序非递归遍历序列为:",pre_order_un,t);
	travel("中序遍历序列为:",mid_order,t);
	travel("后序遍历序列为:",post_order,t);
	travel("按层遍历序列为:",level_order,t);

	return 0;
}
