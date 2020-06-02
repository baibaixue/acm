#include <stdio.h>

int main()
{
	int hour1,minut1;
	int hour2,minut2;
	scanf("%d %d",&hour1,&minut1);
	scanf("%d %d",&hour2,&minut2);
	int ih=hour2-hour1;
	int im=minut2-minut1;
	
	if (im<0){
		im=60+im;
		ih--;
	}
	
	printf("时间差为%d小时%d分",ih,im);
}
