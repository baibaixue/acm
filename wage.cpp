#include <stdio.h>

int main()
{
	const double RATE=8.25;
	const double STANDARD=40;
	double pay=0.0;
	int hours;
	
	printf("�����빤��ʱ�䣺\n");
	scanf("%d",&hours);
	if (hours>STANDARD)
		pay=STANDARD*RATE+(hours-STANDARD)*(RATE*1.5);
	else
		pay=hours*RATE;
		
	printf("���ܹ���Ϊ%fԪ��",pay);
	
	return 0;
	
}
