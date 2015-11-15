#include<stdio.h>

int main(void)
{
    int i,j,num=0,array[3][4]={{7,10,-2,3},{14,20,6,-15},{0,5,27,-7}};
    int *p[3]={&array[0][0],&array[1][0],&array[2][0]};
    for(i=0;i<3;i++)
	for(j=0;j<4;j++)
	    num += *(p[i]+j);
    printf("the num is : %d\n",num);

    return 0;
}
