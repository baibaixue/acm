//10月29号，白雪，素数判定 
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
	int i,n;
	int m=1;  
	for(i=-39;i<=50;i++){//从-39到50循环判断 
		n=i*i+i+41;			
		if(is_prime(n)==0){
			m=0;//出现一个不是素数则给予判断终止循环 
			break;
		}
	} 
	if(m==1){
		printf("OK\n");//都是素数 
	}
	if(m==0){
		printf("Sorry\n");//不都是素数 
	}
	return 0;
}
