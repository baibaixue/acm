//10��29�ţ���ѩ����ٷ���������
#include<stdio.h>
int main(){
	int i,j;
	for(i=0;i<33;i++){//x������33�����α��� 
		for(j=0;j<33;j++){
			if(i*i+j*j==1000){//�жϲ���� 
				printf("x=%d,y=%d\n",i,j);
			}
		}
	}
	return 0;
} 
