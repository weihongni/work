#include"doublelinklist.h"

int main(void)
{
	double_plist h;
	init_doublelist(&h);
	create_doublelist(h);
	show_doublelist(h);
	sort_doublelist(h);
	show_doublelist(h);

	return 0;
}
