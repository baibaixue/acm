//��ѩ����ʽ1-1/2+1/3-....ǰ40���
#include<stdio.h>
int main(){
	int i,a=1;
	double sum=0;
	for(i=1;i<=40;i++){
		sum+=1.0/i*a;
		a=-a;//a��ʾ���� 
	}
	printf("%.2f",sum);
	return 0;
} 
