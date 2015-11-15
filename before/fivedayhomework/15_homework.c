
/*用函数实现数组元素的逆转
 *
 */

#include<stdio.h>

void recur(int a[],int k)
{
    int tmp;
    if(k<0){
	recur((a[k--]),k--);
	tmp = a[0];
	a[0] = a[k-1];
	a[k-1] = tmp;
    }
    for(tmp=0;tmp<5;tmp++);
	printf("%d\n",a[tmp]);

}

int main(void)
{
    int y[] = {1,2,3,4,5};
    recur(y,5);

    return 0;
}
