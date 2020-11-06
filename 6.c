#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main(){
	double r,res;
	int n;
	printf("please input r and n:\n");//提示语句 
	scanf("%lf%d",&r,&n);//输入 
	res=n*r*r*sin(2*pi/n)/2.0;//计算 
	printf("%.2f",res);//输出 
	return 0; 
} 
