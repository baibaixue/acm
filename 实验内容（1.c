//10��29�ţ���ѩ���������ε������ 
#include<stdio.h>
#include<math.h> 
int main(){
	int a,b,c;
	double p;
	scanf("%d%d%d",&a,&b,&c);//���� ����ʵ�� 3 4 5 
	p=(a+b+c)/2.0;//����p 
	double s;
	s=sqrt(p*(p-a)*(p-b)*(p-c));//������� 
	printf("%.3f",s);//���  ��� 6.00 
	return 0;
} 
