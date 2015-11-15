#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>
#include <string.h>

#include <pthread.h>

#define MAX_NAME_LEN 32
struct person_info {
	int sex;
	char name[MAX_NAME_LEN+1];
	int age;
	//....
};

void *sub_thread_routine(void * arg)
{
	int i;
	struct person_info *pInfo = NULL;

	printf("I'm sub thread,my thread ID is:0x%x, arg =%s\n", (int)pthread_self(), (char *)arg);
	
	pInfo = (struct person_info *)malloc(sizeof(struct person_info)); 	
	if(!pInfo) {	/* 内存分配不成功*/
		pthread_exit(NULL);
	}

	pInfo->sex = 1;
	pInfo->age = 18;
	
	bzero(pInfo->name, MAX_NAME_LEN+1);
	int len = strlen((char *)arg);
	if(len > MAX_NAME_LEN) {
		len = MAX_NAME_LEN;
	} 
	strncpy(pInfo->name, arg, len);

	pthread_exit((void *)pInfo);

	//return NULL;
}

void sub_detach_thread(void *arg)
{
	printf("I'm sub detach_thread!\n");
//	pthread_detach(pthread_self()); //设置线程的分离属性
	
	int i;
	for (i = 0; i < 20; i++) {
                printf("I'am in sub detach thread, i =%d\n", i);
                usleep(200000); //sleep 0.2s
        }

        pthread_exit(NULL);
}

int main(void)
{

	pthread_t tid, tdid;

	char *msg = "Hello, 1510";
	struct person_info *pInfo = NULL;

	printf("Thread attribute demo.\n");

///////////////////////////////////////////////////
	/* 1.定义一个多线程的属性的变量*/
	pthread_attr_t attr; 
	
	/*2.初始化线程属性 */
	pthread_attr_init(&attr);
	
	/* 3. 获取和设置各种属性*/
	size_t stacksize;
	pthread_attr_getstacksize(&attr, &stacksize);
	printf("thread attribute, stacksize =%dMB\n", stacksize/1024/1024);
	pthread_attr_setstacksize(&attr, 2 * stacksize); /* 把线程栈大小扩大一倍 */
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); /* 设置线程属性为分离属性*/

	/*4.使用线程属性创建线程 */
	pthread_create(&tdid, &attr,(void *)sub_detach_thread, NULL);
	/*5.删除线程属性 */
	pthread_attr_destroy(&attr);
////////////////////////////////////////////////////////

	pthread_create(&tid, NULL, sub_thread_routine, (void *)msg);
	
	printf("after pthread_create()\n");
	
	pthread_join(tid, (void *)&pInfo);
	//pthread_join(tdid, NULL);  /* 因为sub_detach_thread设置了分离属性，所以主线程不需要pthread_join() */

	printf("after pthread_join()\n");
	
	if(pInfo) {
		printf("The return value: sex=%d, name=%s, age=%d\n", pInfo->sex, pInfo->name, pInfo->age);
		free(pInfo);	
	}
	sleep(5); //等待分离线程执行完毕
	return 0;
}
