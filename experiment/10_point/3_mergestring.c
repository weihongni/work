#include<stdio.h>
#include<string.h>

int main(void)
{
#if 0
    int i = 0,j = 0;
    char str[20],str1[20]="Hello ",str2[20]="world";
    char *p,*p1,*p2;
    p = str;
    p1 = str1;
    p2 = str2;
    while(*(p1+i)!='\0')
	i++;
    strcpy(str,str1);
    while(*(p2+j)!='\0'){
	*(p+i+j)=*(p2+j);
	j++;
    }
    *(p+i+j)='\0';
    puts(str);
#endif
    char a[]="Hello ",b[]="World",c[20],*p;
    int i = 0,k = 0;
    while(a[i]!='\0')
	c[k++] = a[i++];
    c[k] = '\0';
    p = b;
    strcat(c,p);
    puts(c);

    return 0;
}
