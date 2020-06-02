#include <stdio.h>

int main()
{
	int a,b,x;
	//int a1=a,b1=b;
	//printf("请输入两个整数:");
	scanf("%d %d",&a,&b);
	while(b!=0){
		x=a%b;
		a=b;
		b=x;
	}
	printf("%d\n",a);
	//printf("%d和%d的最大公约数为%d",a1,b1,a);
	return 0;
}
