#include<stdio.h>
int main(){
	int d,h,m;
	int sum;
	printf("please input days,hours and minutes.\n");//提示语句 
	scanf("%d%d%d",&d,&h,&m);//输入 
	sum=d*24*60+h*60+m;//计算 
	printf("%d",sum);//输出 
	return 0;
}
