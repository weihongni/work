#include<stdio.h>

int main(void)
{
	int i,m;
	printf("Please input a integer!");
	scanf("%d",&m);
	while(m>1){
		for(i=2;i<m;i++)
			if(m%i == 0)
				break;
		if(i>=m){
			printf("%d\n",m);
			return -1;
		}
		m--;
	}

	return 0;
}
