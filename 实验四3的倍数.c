//10月29日，白雪，输出三的倍数的和
#include<stdio.h>
int main(){
	int n,i;
	int sum=0;
	do{//循环输入 
		scanf("%d",&n);//测试数据2 3 4 5 6 0 
		if(n!=0&&(n%3==0)){//判断是否为零和为三 
			sum+=n;
		}
	}while(n!=0);
	printf("%d\n",sum);//结果9 
	return 0;
} 
