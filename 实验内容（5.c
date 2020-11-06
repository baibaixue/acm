//10月29日，白雪，计算表达式a+=a-=a*a并打印
#include<stdio.h>
int main(){
	int a=3;//a为3 
	printf("%d",a+=a-=a*a);//计算结果为-12 
	return 0;
} 
