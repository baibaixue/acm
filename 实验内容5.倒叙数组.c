#include<stdio.h>//�������� 11��19�� ��ѩ 
int main(){
	int c[]={1,3,5,7,9};//�������� 
	int i;
	int t;
	for(i=0;i<2;i++){//������ӦԪ��λ�� 
		t=c[i];
		c[i]=c[4-i];
		c[4-i]=t;
	}
	for(i=0;i<5;i++){
		printf("%d ",c[i]);//��� 
	}
	printf("\n");
	return 0;
} 
