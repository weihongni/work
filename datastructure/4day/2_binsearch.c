#include <stdio.h>

#define N 12

int binsearch(int *a,int key);
void show(int *a);
int main(void)
{
      int a[N] = {3,12,18,20,32,55,60,68,80,86,90,100};
      int key,ret;
      show(a);
      while(1){
	    printf("请输入key:");
	    scanf("%d",&key);
	    ret = binsearch(a,key);  //找到返回记录的下标，失败返回-1
	    if(ret == -1){
		  printf("记录不存在!\n");
	    }else
		  printf("key为%d的记录在%d位置！\n",key,ret);
      }

      return 0;
}

int binsearch(int *a,int key)
{
      int low,high,mid;
      for(low = 0,high = N-1; low <= high;){
	    mid = (low + high) / 2;
	    if(key == a[mid])
		  return mid;
	    else if(key < a[mid])
		  high = mid -1;
	    else
		  low = mid + 1;
      }
      return -1;
}
void show(int *a)
{
      int i;
      for(i = 0; i < N; i++)
	    printf("%d\t",a[i]);
      printf("\n");
}

