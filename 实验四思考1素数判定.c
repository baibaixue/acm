//10��29�ţ���ѩ�������ж� 
#include<stdio.h>
int  is_prime(int i)//�����ж��Ƿ�Ϊ�����ĺ��� 
{	int k;
	int a=1; 
	for(k=2;k<i;k++){
		if(i%k==0){
			a=0;
			break;
		}
	}
	return a;
}



int main(){
	int i,n;
	int m=1;  
	for(i=-39;i<=50;i++){//��-39��50ѭ���ж� 
		n=i*i+i+41;			
		if(is_prime(n)==0){
			m=0;//����һ����������������ж���ֹѭ�� 
			break;
		}
	} 
	if(m==1){
		printf("OK\n");//�������� 
	}
	if(m==0){
		printf("Sorry\n");//���������� 
	}
	return 0;
}
