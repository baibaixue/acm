#include <stdio.h>

int main()
{
	int AMOUNT;
	int price,amount;
	
	printf("�������ܽ�Ԫ����");
	scanf("%d",&AMOUNT);
	printf("�������Ԫ����");
	scanf("%d",&price);
	printf("������������������"); 
	scanf("%d",&amount);
	
	int change=AMOUNT - price*amount;
	
	printf("����%dԪ\n", change);
	
	return 0;
}
