#include <stdio.h>

int main()
{
	int a,b;
	printf("请输入两个整数：");
	scanf("%d %d",&a,&b);
	double averange=(a+b)/2.0;
	printf("%d和%d的平均数为%f",a,b,averange);
	
	return 0;
}
