#include<stdio.h>
#define pi 3.14159
int main(){
	double r,v;
	printf("please input r:\n");//��ʾ��� 
	scanf("%lf",&r);//���� 
	v=4/3.0*pi*r*r*r;//���� 
	printf("v=%.2f\n",v);//��� 
	return 0;
} 
