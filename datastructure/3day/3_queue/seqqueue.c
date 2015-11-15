#include"seqqueue.h"

int main(void)
{
	seq_pqueue q;
	datatype data;
	int a;
	init_seqqueue(&q);

	while(1)
	{
		printf("Please input a integer!\n");
		a = scanf("%d",&data);
		if(a == 1)
		{
			in_seqqueue(q,data);
			show_seqqueue(q);
		}

		else
		{
			out_seqqueue(q,&data);
			printf("Out is %d\n",data);
			show_seqqueue(q);
			while(getchar() != '\n');
		}

	}

	return 0;
}
