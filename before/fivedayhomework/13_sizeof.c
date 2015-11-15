#include<stdio.h>

typedef union{
    long i;
    int k[5];
    char c;}DATE;

int main(void)
{
    struct data{
    int cat;
    DATE cow;
    double dog;}too;
    DATE max;

    printf("%d\n",sizeof(too)+sizeof(max));
    printf("max = %d\n",sizeof(max));
    printf("too = %d\n",sizeof(too));
    printf("long = %d\n",sizeof(long));
    printf("double = %d\n",sizeof(double));

    return 0;
}
