#include<stdio.h>
//#include<string.h>
int main(){
	int a[1010]={0};
	//memset(a,0,sizeof(a));��ʼ������Ϊ�� 
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n&&i*j<=n;j++){
				a[i*j]=!a[i*j];
			}
		}
		for(int i=0;i<=n;i++){
			if(a[i]!=0){//int frist=1; 
				printf("%d ",i);//if(a[i]){if (frist) frist=0;else printf(" ");printf("%d",i);}//������֮������һ���ո� 
			}
		}
		printf("\n"); 
	}
	return 0;
}
