//#include<cstdio>
//#include<iostream>(���س�ʱ�� 
//#include<algorithm>
//#include<string.h>
//#define maxn 30
//using namespace std;
//int num[maxn];
//int main(){
//	int k;
//	while(scanf("%d",&k)!=EOF&&k
//	){
//		int ans=k;
//		for(;;ans++){
//			memset(num,0,sizeof(num));
//			int count=ans;
//			int n=1;
//			int flag=0;
//			for(;;){//��ѭ����Ϊstart=(start+m-1��%num�� 
//				int a=n%(2*k);
//				if(a==0){
//					a=2*k;
//				}
//				if(count!=1&&num[a]!=1){
//					count--;;
//				}else if(count==1&&num[a]!=1){
//					if(a>k){
//						num[a]=1;
//						count=ans;
//						flag++;
//					}else{
//						break;
//					}
//				}
//				if(flag==k){
//					printf("%d\n",ans);
//					break;
//				}
//				n++;
//			}
//			if(flag==k){
//				break;
//			}
//		}
//	}
//	return 0;
//} 
#include<cstdio>
int arr[20];
int main()
{

	for(int i=1;i<15;i++){
		int num=2*i;//������ 
		int  m=1;//���� 
		int start=0;//��ʼ�˱�� 
	    for(;num>i;){//������С��iʱ 
			start=(start+m-1)%num--;//ÿ�α�������ʱ���� 
	        if(start<i){//��ʼ������Ϊ���� 
				m++;//����������һ 
				num=2*i;//��ʼ������ 
	        	start=0;//��ʼ��ʼ�˱�� 
	        	continue;//������һ��ѭ�� 
	        	}
	    	arr[i]=m;//���ֵ 
	    	}	
		}
	int k;
	while(scanf("%d",&k)!=EOF&&k){
		printf("%d\n",arr[k]);
	}
}
