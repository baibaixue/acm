#include<stdio.h>
#include<math.h>
int main(){
	double x1,x2,y1,y2;
	double res;
	printf("please input x1,y1,x2,y2:\n");//��ʾ��� 
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);//���� 
	res=sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));//���� 
	printf("%.2f\n",res);//��� 
	return 0;
} 
