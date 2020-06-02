//10月29号，白雪，验证哥德巴赫猜想
#include<stdio.h>
int  is_prime(int i)//定义判断是否为素数的函数 
{	int k;
	int a=1; 
	for(k=2;k<i;k++){
		if(i%k==0){
			a=0;
			break;
		}
	}
	return a;
}



int main(){
	int i,j,n;
	int m=0;
	int count=0;
	for(n=6;n<=400;n+=2){//题目没有给定的测试范围，先验证400之前的数 
	m=0;
		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				if(is_prime(i)&&is_prime(j)&&i+j==n){//i,j都是素数并且和为n 
					m=1;
					break; 
				}
				if(is_prime(i)&&is_prime(j)&&i+j==n){
					break; 
			}
		}
	}
	if(m==1){
		count++;
	} 
}
	if(count==(400-6)/2+1){//计数器的值为所有测试的偶数 
		printf("OK\n");// 成立 
	}
	else{
		printf("Sorry\n");// 不成立 
	}
	return 0;
} 
