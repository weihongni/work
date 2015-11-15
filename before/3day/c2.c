#include<stdio.h>

float main(void)
{
	int i,j,k;
	k = 5;
	double b,a[k];
	printf("Please input some numbers :");
	for(i=0;i<k;i++)
		scanf("%lf",&a[i]);
	max = fun(a);
	printf("The max sub is : %f\n",max);
	double fun();
	for(i=0;i<(k-1);i++)
	{
		for(j=i+1;j<k;j++)
			if(a[i]<=a[j])
			{
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
	}
	b = a[0]-a[k-1];

	return 0;
}
