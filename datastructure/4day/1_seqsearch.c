#include <stdio.h>

#define N 8

int seqsearch(int *a,int key);
void show(int *a);

int main(void)
{
      int a[N] = {2,7,5,8,4,3,9,1};
      int key,ret;
      show(a);
      while(1){
	    printf("请输入key:");
	    scanf("%d",&key);
	    ret = seqsearch(a,key);  //找到返回记录的下标，失败返回-1
	    if(ret == -1){
		  printf("记录不存在!\n");
	    }else
		  printf("key为%d的记录在%d位置！\n",key,ret);
      }

      return 0;
}

int seqsearch(int *a,int key)
{
      int i;
      for(i = N-1; i>=0; i--)
	    if(key == a[i])
		  return i;
      return i;
}
void show(int *a)
{
      int i;
      for(i = 0; i < N; i++)
	    printf("%d\t",a[i]);
      printf("\n");
}

