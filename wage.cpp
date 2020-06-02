#include <stdio.h>

int main()
{
	const double RATE=8.25;
	const double STANDARD=40;
	double pay=0.0;
	int hours;
	
	printf("请输入工作时间：\n");
	scanf("%d",&hours);
	if (hours>STANDARD)
		pay=STANDARD*RATE+(hours-STANDARD)*(RATE*1.5);
	else
		pay=hours*RATE;
		
	printf("本周工资为%f元。",pay);
	
	return 0;
	
}
