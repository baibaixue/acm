//10��29�գ���ѩ��������ı����ĺ�
#include<stdio.h>
int main(){
	int n,i;
	int sum=0;
	do{//ѭ������ 
		scanf("%d",&n);//��������2 3 4 5 6 0 
		if(n!=0&&(n%3==0)){//�ж��Ƿ�Ϊ���Ϊ�� 
			sum+=n;
		}
	}while(n!=0);
	printf("%d\n",sum);//���9 
	return 0;
} 
