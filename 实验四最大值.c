//10��29�գ���ѩ���ҳ����ֵ����ֵ
#include<stdio.h>
int main(){
	double a,b,c,max;
	scanf("%lf%lf%lf",&a,&b,&c);//�������� 2 7 4 
	max=a;
	if(max<b){
		max=b;//ȡa,b�е����ֵ 
	}
	if(max<c){
		max=c;//ȡ���ֵ 
	}
	printf("%.2f\n",max);//���7 
	return 0;
} 
