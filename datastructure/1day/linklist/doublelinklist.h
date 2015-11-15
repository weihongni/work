#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int datatype;
typedef struct doublelist{
	datatype data;
	struct doublelist *next,*prior;
}double_list,*double_plist;

#endif
