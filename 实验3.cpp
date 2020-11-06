#include<stdio.h>
int main(){
	double e,m;
	printf("please input english score:");
	scanf("%lf",&e);//输入英语成绩 
	printf("please input math score:");
	scanf("%lf",&m);//输入数学成绩 
	printf("averange score:%.2f\n",(e+m)/2.0);//输出平均成绩 
	return 0;
} 
