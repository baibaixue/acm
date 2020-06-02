#include <stdio.h>

int main()
{
	int x,x1;
	printf("请输入一个整数：");
	scanf("%d",&x);
	x1=x;
	int n=1;
	while(x1>9){
		x1/=10;
		n*=10;	
	}

	do{
		int a=x/n;
		printf("%d",a);
		if(n>9){
			printf(" ");
		}
		x=x%n;
		n=n/10;
	}while (n>0);
	return 0;
	
}
