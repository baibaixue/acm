#include <stdio.h>

int main(){
	int num,x;
	printf("������һ����������");
	scanf("%d",&num);
	do{
		x=num%10;
		printf("%d",x);
		num/=10;
		
	}while(num>0);
	return 0;
} 
