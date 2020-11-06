//10月29日，白雪，解一元二次方程
#include<stdio.h>
#include<math.h>
int main(){
	double a,b,c;
	double t;
	double x1,x2;
	printf("please input a,b,c:\n");//提示语句 
	scanf("%lf%lf%lf",&a,&b,&c);//输入a,b,c 测试数据1 2 1 ,1 5 4
	t=b*b-4*a*c;//计算t 
	if(t>0){//两个解的情况 
		x1=(-b+sqrt(t))/2*a;
		x2=(-b-sqrt(t))/2*a;
		printf("x1=%.2f,x2=%.2f\n",x1,x2);//结果x1=-1.00,x2=-4.00 
	}else if(t==0){//一个解 
		printf("x=%.2f\n",(-b)/2*a);//结果x=-1.00
	}else{//无解 
		printf("No answer!\n");
	}
	return 0;
} 
