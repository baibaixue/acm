//10��29�գ���ѩ������ֶκ���
#include<stdio.h>
#include<math.h> 
int main(){
	double x,res;
	scanf("%lf",&x);//��������3 
	if(x<-5){
		res=3*x*x+2*x-1;
	}else if(x<=5&&x>=-5){
		res=x*sin(x)+2*x*x;
	}else{
		res=sqrt(x-5)+log10(x);
	}//������������� 
	printf("%.3f\n",res);//���18.632 
	return 0;
} 
