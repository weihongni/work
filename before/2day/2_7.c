#include<stdio.h>

int main(void)
{
	int b,i,j,k,l;
	char c;
	printf("Please input a upalphabet :");
	scanf("%c",&c);
	
	b = c - 'A' + 1;
	for(i=0;i<b;i++){
		for(j=0;j<b-i;j++){
			printf(" ");
		}
		for(k=0;k<i+1;k++){
			c = 'A' + k;
			printf("%c",c);

		}
		for(l=i;l;l--){
			printf("%c",'A'+l-1);
		}
		printf("\n");
	}

	return 0;
}
