#include <stdio.h>

int main()
{
	int x;
	printf("������һ����λ����");
	scanf("%d",&x);
	int a=x/100;
	int c=x%10;
	int b=(x%100)/10;
	printf("���Ϊ��%d",c*100+b*10+a);
	
	return 0;
	
}
