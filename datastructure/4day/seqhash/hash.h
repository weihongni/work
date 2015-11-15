#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

//#define p  13
typedef int datatype;

typedef struct hashtbl{
    datatype *h;   //h为指向hash表空间的指针
    int length;	    //length为hash表的空间长度
}hash_tbl,*hash_ptbl;

int p;

extern void init_hash_seq(int m,hash_ptbl * H);
extern void create_hash_seq(int n,datatype *a,hash_ptbl hp);
extern int search_hash_seq(int key,hash_ptbl hp);
extern void show_hash_seq(hash_ptbl hp,int hash_val);
#endif
