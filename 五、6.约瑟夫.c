#include<stdio.h>//Լɪ������ 11��18�� ��ѩ
int main(){
	int m,n;
	int M[1000];
	int i,j;
	printf("printf m,n:\n");
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++){
		M[i]=i;//��m���˱�� 
	} 
	int k=1;
	int count=0;//������Ա������ 
	i=1;
	int x;
	for(;;){
		x=i%m;
		if(i%m==0){//ԲȦ����ȡ���ҳ���Ӧ���±� 
			x=m;
		}
		if(k==n&&M[x]!=0){//kΪ���� 
			printf("%d ",M[x]); 
			M[x]=0;//ת��Ϊ0��ʾ���� 
			k=1;
			count++;
		}else if(M[x]!=0){
			k++;
		}
		i++;
		if(count==m){//m����ȫ�����н���ѭ�� 
			break;
		}
	} 
	return 0;
} 
