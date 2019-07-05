#include <stdio.h>

int main()
{
	int hour1,minut1;
	int hour2,minut2;
	scanf("%d %d",&hour1,&minut1);
	scanf("%d %d",&hour2,&minut2);
	int time1=hour1*60+minut1;
	int time2=hour2*60+minut2;
	int time=time2-time1;
	printf("时间差为%d小时%d分",time/60,time%60);
	
	return 0;
}
