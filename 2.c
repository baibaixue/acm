#include<stdio.h>
#include<math.h>
int main(){
	double x1,x2,y1,y2;
	double res;
	printf("please input x1,y1,x2,y2:\n");//提示语句 
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);//输入 
	res=sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));//计算 
	printf("%.2f\n",res);//输出 
	return 0;
} 
