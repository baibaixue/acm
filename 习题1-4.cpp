#include<stdio.h>

int main()
{
	int a,b;
	double result;
	printf("please input a and b:");
	scanf("%d%d",&a,&b);
	result=(-b)/a;
	printf("x=%f",result);
	return 0;
}
