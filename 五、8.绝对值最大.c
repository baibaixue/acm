#include<stdio.h>//����ֵ��� 11��18�� ��ѩ
#include<math.h>
int main(){
	int s[10][10];
	int i,j;
	printf("print 5*6 groups:\n");
	for(i=0;i<6;i++){
		for(j=0;j<5;j++){
			scanf("%d",&s[i][j]);//����5*6���� 
		}
	}
	int max=fabs(s[0][0]);//��ʼ�����ֵ 
	int x,y;
	for(i=0;i<6;i++){
		for(j=0;j<5;j++){
			if(max<fabs(s[i][j])){//�ҳ����ֵ 
				max=fabs(s[i][j]); 
				x=i;y=j;//������ֵ��λ�� 
			}
		}
	}
	printf("%d %d %d",s[x][y],x+1,y+1);
	return 0;
} 
