//10月29日，白雪，找出最大值并赋值
#include<stdio.h>
int main(){
	double a,b,c,max;
	scanf("%lf%lf%lf",&a,&b,&c);//测试数据 2 7 4 
	max=a;
	if(max<b){
		max=b;//取a,b中的最大值 
	}
	if(max<c){
		max=c;//取最大值 
	}
	printf("%.2f\n",max);//结果7 
	return 0;
} 
