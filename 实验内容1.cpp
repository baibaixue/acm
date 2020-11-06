#include<stdio.h>
int main(){
	const double pi=3.1415926;//定义常数pi 
	double r=3.0,d,c,s;//定义变量 
	d=2*r;//计算直径 
	c=2*pi*r;//计算周长 
	s=pi*r*r;//计算半径 
	printf("d=%.2f c=%.2f d=%.2f",d,c,s);//保留两位小数输出 
	return 0;
}
