#include <stdio.h>

int main()
{
	int AMOUNT;
	int price,amount;
	
	printf("请输入总金额（元）：");
	scanf("%d",&AMOUNT);
	printf("请输入金额（元）：");
	scanf("%d",&price);
	printf("请输入数量（个）："); 
	scanf("%d",&amount);
	
	int change=AMOUNT - price*amount;
	
	printf("找您%d元\n", change);
	
	return 0;
}
