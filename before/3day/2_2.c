#include<stdio.h>

float main(void)
{
	float t,a[10];
	int i,j;
	printf("Please input ten numbers :");
	for(i=0;i<10;i++)
		scanf("%f",&a[i]);
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
			if(a[i]<=a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	}
	t = a[0]-a[9];
	printf("%f\n",t);

	return 0;
}
