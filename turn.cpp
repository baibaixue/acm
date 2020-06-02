#include <stdio.h>

int main()
{
	int x;
	printf("请输入一个三位数：");
	scanf("%d",&x);
	int a=x/100;
	int c=x%10;
	int b=(x%100)/10;
	printf("结果为：%d",c*100+b*10+a);
	
	return 0;
	
}
