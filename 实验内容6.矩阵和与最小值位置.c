#include<stdio.h>//�ҳ�������Сֵ������Ԫ��֮�� 11��19�� ��ѩ 
int main(){
	int i,j;
	int c[5][5];
	int sum=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&c[i][j]);
			sum+=c[i][j];//��ȡ���벢��� 
		}
	}
	int min=c[0][0],x,y;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(min>c[i][j]){
				min=c[i][j];
				x=i;y=j;//�ҳ���Сֵ���� 
			}
		}
	}
	printf("sum=%d x=%d y=%d\n",sum,x+1,y+1);
	return 0;
} 
