//10月29日，白雪，计算分段函数
#include<stdio.h>
#include<math.h> 
int main(){
	double x,res;
	scanf("%lf",&x);//测试数据3 
	if(x<-5){
		res=3*x*x+2*x-1;
	}else if(x<=5&&x>=-5){
		res=x*sin(x)+2*x*x;
	}else{
		res=sqrt(x-5)+log10(x);
	}//分三种情况计算 
	printf("%.3f\n",res);//结果18.632 
	return 0;
} 
