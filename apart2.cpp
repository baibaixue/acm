#include <stdio.h>

int main(){
	int num,x,result=0;
	printf("������һ����������");
	scanf("%d",&num);
	do{
		x=num%10;
		result=result*10+x;
		num/=10;
		
	}while(num>0);
	printf("%d",result);
	return 0;
} 
