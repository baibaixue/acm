//��ѩ����ӡ�˷��ھ�
#include<stdio.h>
int main(){
	int i,j,n,m;
	for(i=1;i<10;i++){
		for(j=1;j<=i;j++){
			printf("%d X %d = %2d ",j,i,j*i);//��ӡ 
		}
		printf("\n");
	}
	return 0;
} 
