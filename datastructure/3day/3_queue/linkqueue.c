#include"linkqueue.h"

int main(void)
{
	link_pqueue q;
	datatype data;
	int a;
	init_linkqueue(&q);

	while(1)
	{
		printf("Please input a integer!\n");
		a = scanf("%d",&data);
		if(a == 1)
		{
			in_linkqueue(q,data);
			show_linkqueue(q);
		}

		else
		{
			out_linkqueue(q,&data);
			printf("Out is %d\n",data);
			show_linkqueue(q);
			while(getchar() != '\n');
		}

	}

	return 0;
}
