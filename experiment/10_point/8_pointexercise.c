#include<stdio.h>
#include<string.h>

int main(void)
{
    int i,j,a[10]={0};
    int *pa = a;
    char *p,str[100];
    printf("Please enter a string!\n");
//    scanf("%s",str);
    gets(str);
    p = str;
    j = 0;
    printf("%d\n",strlen(str));
    puts(str);
    for(i=0;i<strlen(str);i++)
    {
	if((47<p[i])&&(p[i]<58))
	{
	    if(i==0)
		pa[j] = (p[i]-48);
	    else
	    {
		if((p[i-1]<48)||(p[i-1]>57))
		    pa[j] = (p[i]-48);
		if((p[i-1]>47)&&(p[i-1]<58))
		    pa[j] = pa[j] * 10 + (p[i]-48);
		if((p[i+1]<48)||(p[i+1]>57))
		{
		    j++;
		    printf("%d\n",j);
		}
	    }
	}
    }
    printf("A tolal of %d integer\n",j);
    for(i=0;i<j;i++)
	printf("%d\t",pa[i]);
    printf("\n\n");

    return 0;
}
