//10月29日，白雪，求一个三位数每一位数的立方和 
#include<stdio.h>
#include<math.h>
int main(){ 
	int n,a,b,c;
	int sum;
	scanf("%d",&n);//输入三位数  测试实例 123 
	a=(n/100);//计算百位数 
	n%=100;
	b=(n/10);//十位数 
	c=(n%10);//个位数 
	sum=a*a*a+b*b*b+c*c*c;//计算和 
	printf("%d",sum); //输出  结果36 
	return 0;
}
