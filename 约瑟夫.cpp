#include<cstdio>
int M[10000];
int main(){
	int k,m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		for(int i=1;i<=m*2;i++){
			M[i]=i;//��m���˱�� 
		} 
		int k=1;
		int count=0;//������Ա������ 
		int i=1;
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
		printf("\n");
	}
	return 0;
} 
