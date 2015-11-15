#include<stdio.h>

void fun(char x,int y,int z)
{
    int i,j;
    for(i=0;i<z;i++){
	for(j=0;j<y;j++)
	    printf("%c%c",x,' ');
	printf("\n");
    }
    printf("\n");
    return;
}

int main(void)
{
    int a,b;
    char c;
    printf("Please input a char!\n");
    c = getchar();
    printf("Please input two integer!\n");
    scanf("%d%d",&a,&b);
    fun(c,a,b);

    return 0;
}
