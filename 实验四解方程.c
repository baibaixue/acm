//10��29�գ���ѩ����һԪ���η���
#include<stdio.h>
#include<math.h>
int main(){
	double a,b,c;
	double t;
	double x1,x2;
	printf("please input a,b,c:\n");//��ʾ��� 
	scanf("%lf%lf%lf",&a,&b,&c);//����a,b,c ��������1 2 1 ,1 5 4
	t=b*b-4*a*c;//����t 
	if(t>0){//���������� 
		x1=(-b+sqrt(t))/2*a;
		x2=(-b-sqrt(t))/2*a;
		printf("x1=%.2f,x2=%.2f\n",x1,x2);//���x1=-1.00,x2=-4.00 
	}else if(t==0){//һ���� 
		printf("x=%.2f\n",(-b)/2*a);//���x=-1.00
	}else{//�޽� 
		printf("No answer!\n");
	}
	return 0;
} 
