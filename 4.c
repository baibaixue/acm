#include<stdio.h>
int main(){
	double a,d,sum;
	int n;
	printf("please input a d and n:\n");//��ʾ��� 
	scanf("%lf%lf%d",&a,&d,&n);//���� 
	sum=a*n+n*(n-1)*d/2;//���� 
	printf("sum=%.2f\n",sum);//��� 
	return 0;
}
