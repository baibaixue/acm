#include<stdio.h>
int leap_year(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
		return 1;
		else 
		return 0;
}
int main()
{
	int year,month,day,days;
	int sumdays[12]={0,31,59,90,121,151,181,212,243,273,304,334};
		while(scanf("%d/%d/%d",&year,&month,&day)!=EOF)
		{
			days=sumdays[month-1]+day;
			if(leap_year(year)&&month>2)
				days++;
				printf("%d\n",days);
	}
return 0;
}

