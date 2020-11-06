//10月29号，白雪，求三角形的面积。 
#include<stdio.h>
#include<math.h> 
int main(){
	int a,b,c;
	double p;
	scanf("%d%d%d",&a,&b,&c);//输入 测试实例 3 4 5 
	p=(a+b+c)/2.0;//计算p 
	double s;
	s=sqrt(p*(p-a)*(p-b)*(p-c));//计算面积 
	printf("%.3f",s);//输出  结果 6.00 
	return 0;
} 
