#include<stdio.h>

struct A{
    int year;
    int month;
    int day;
};

int fun(struct A b)
{
    int i,days = 0;
    printf("%d.%02d.%02d\n",b.year,b.month,b.day);
    for(i=1;1<b.month;i++)
    {
	switch(i){
	    case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
		days += 31;
		break;
	    case 4:
	    case 6:
	    case 9:
	    case 11:
		days += 30;
		break;
	    case 2:
		if((!(b.year%4)&&b.year%100)||!(b.year%400))
		    days += 29;
		else
		    days += 28;

	}
    }
    return days+b.day;
}

int main(void)
{
    struct A date;
    printf("please input the time,for example: 2015.10.10\n");
    scanf("%d.%d.%d",&date.year,&date.month,&date.day);
    printf("%d.%d.%d is this year %d day.\n",date.year,date.month,date.day,fun(date));

    return 0;
}
