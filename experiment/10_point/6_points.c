#include<stdio.h>
#include<string.h>

int main(void)
{
    int i,j;
    char *str[5]={"a","d","c","e","b"},*strp;
    strp = NULL;
    for(i=0;i<4;i++)
	for(j=i+1;j<5;j++)
	    while(strcmp(str[i],str[j])>0)
	    {
		printf("%s|%s\n",str[i],str[j]);
		strp = str[i];
		str[i] = str[j];
		str[j] = strp;
		printf("%s|%s\n\n",str[i],str[j]);
	    }
    for(i=0;i<5;i++)
	printf("%s",str[i]);
    printf("\n");

    return 0;
}
