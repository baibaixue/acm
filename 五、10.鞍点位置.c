#include<stdio.h>//����λ�� 11��18�� ��ѩ
int main(){
	int c[10][10];
	int n;
	int i,j,l;
	scanf("%d",&n);//n�׷��� 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&c[i][j]);//���뷽�� 
		}
	}
	int x,y;
	int k;
	int t;
	int kase=0;//�����ڰ��� 
	for(i=0;i<n;i++){//�ӵ�һ�п�ʼ�� 
		t=c[i][0];//t�������ֵ 
		x=i;y=0;
		for(j=0;j<n;j++){
			if(c[i][j]>t){
				x=i;y=j;//���ÿһ�е����ֵ 
				t=c[i][j];
			}
		}
		k=1; //��������а������Ϊk=1�� 
		for(l=0;l<n;l++){
			if(t>c[l][y]){//����һ�е����ֵ����һ�е�ֵ�Ƚ� 
				k=0;//���а��㲻���� 
			}
		}
		if(k==1){
			printf("%d %d\n",y+1,x+1);//��� 
			kase=1;//������� 
		}
	}
	if(kase==0){
		printf("N0\n");
	} 
	return 0;
} 
