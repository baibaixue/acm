#include<stdio.h>
int main(){
	double a,d,sum;
	int n;
	printf("please input a d and n:\n");//提示语句 
	scanf("%lf%lf%d",&a,&d,&n);//输入 
	sum=a*n+n*(n-1)*d/2;//计算 
	printf("sum=%.2f\n",sum);//输出 
	return 0;
}
