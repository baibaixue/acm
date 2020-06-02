#include <stdio.h>

int main(){
	int num,x,result=0;
	printf("请输入一个正整数：");
	scanf("%d",&num);
	do{
		x=num%10;
		result=result*10+x;
		num/=10;
		
	}while(num>0);
	printf("%d\n",result);
	num=result;
	do{
	x=num%10;
	printf("%d",x);
	num/=10;
	if (num>0){
		printf(" ");
	}	
	}while(num>0);
	return 0;
	} 
