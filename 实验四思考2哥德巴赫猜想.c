//10��29�ţ���ѩ����֤��°ͺղ���
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
	int i,j,n;
	int m=0;
	int count=0;
	for(n=6;n<=400;n+=2){//��Ŀû�и����Ĳ��Է�Χ������֤400֮ǰ���� 
	m=0;
		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				if(is_prime(i)&&is_prime(j)&&i+j==n){//i,j�����������Һ�Ϊn 
					m=1;
					break; 
				}
				if(is_prime(i)&&is_prime(j)&&i+j==n){
					break; 
			}
		}
	}
	if(m==1){
		count++;
	} 
}
	if(count==(400-6)/2+1){//��������ֵΪ���в��Ե�ż�� 
		printf("OK\n");// ���� 
	}
	else{
		printf("Sorry\n");// ������ 
	}
	return 0;
} 
