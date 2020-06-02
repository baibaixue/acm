#include <stdio.h>

int main(){
	int a,b;
	printf("请输入两个整数：");
	scanf("%d %d",&a,&b);
	int i;
	for(i=a;i>0;i--){
		if(a%i==0&&b%i==0){
			break;	
		}	
	} 
	printf("%d和%d的最大公约数是%d。",a,b,i);
	return 0;
}
