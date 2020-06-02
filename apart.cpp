#include <stdio.h>

int main(){
	int num,x;
	printf("请输入一个正整数：");
	scanf("%d",&num);
	do{
		x=num%10;
		printf("%d",x);
		num/=10;
		
	}while(num>0);
	return 0;
} 
