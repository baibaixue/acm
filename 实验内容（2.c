//10��29�գ���ѩ����һ����λ��ÿһλ���������� 
#include<stdio.h>
#include<math.h>
int main(){ 
	int n,a,b,c;
	int sum;
	scanf("%d",&n);//������λ��  ����ʵ�� 123 
	a=(n/100);//�����λ�� 
	n%=100;
	b=(n/10);//ʮλ�� 
	c=(n%10);//��λ�� 
	sum=a*a*a+b*b*b+c*c*c;//����� 
	printf("%d",sum); //���  ���36 
	return 0;
}
