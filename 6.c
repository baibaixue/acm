#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main(){
	double r,res;
	int n;
	printf("please input r and n:\n");//��ʾ��� 
	scanf("%lf%d",&r,&n);//���� 
	res=n*r*r*sin(2*pi/n)/2.0;//���� 
	printf("%.2f",res);//��� 
	return 0; 
} 
