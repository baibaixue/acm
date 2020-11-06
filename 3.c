#include<stdio.h>
#define pi 3.14159
int main(){
	double r,v;
	printf("please input r:\n");//提示语句 
	scanf("%lf",&r);//输入 
	v=4/3.0*pi*r*r*r;//计算 
	printf("v=%.2f\n",v);//输出 
	return 0;
} 
