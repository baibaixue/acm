#include<stdio.h>
int grade[15];//��ƽ���ɼ��������ͳɼ� 11��19�� ��ѩ 
int main(){
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&grade[i]);//��¼�ɼ� 
	}
	int max,min;
	double ave;
	max=grade[0],min=grade[0],ave=grade[0];
	for(i=1;i<10;i++){
		if(min>grade[i]){
			min=grade[i];//�����ɼ� 
		}if(max<grade[i]){
			max=grade[i];//����С�ɼ� 
		}
		ave+=grade[i];//���ܳɼ� 
	}
	printf("ave=%f,max=%d,min=%d\n",ave/10,max,min);
	return 0;
} 
