#include<stdio.h> 
int main(){
	int a;//定义一个整型变量
	printf("please input an int:");//提示语句 
	scanf("%d",&a);//赋值
	printf("%d\n",a);//打印 
	double b;//定义一个实型变量 
	printf("please input a double:");//提示语句 
	scanf("%lf",&b);//赋值
	printf("%.2f\n",b);//保留两位小数输出
	char n,m;//定义两个字符变量
	printf("please input two chars:");//提示语句
	scanf("%c %c",&n,&m);//赋值 
	printf("%d\n",n+m);//以整数形式输出
	printf("%c\n",n+m);//以字符形式输出
	return 0; 
	 
}
