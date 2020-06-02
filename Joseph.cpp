//#include<cstdio>
//#include<iostream>(严重超时） 
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
//			for(;;){//该循环改为start=(start+m-1）%num； 
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
		int num=2*i;//总人数 
		int  m=1;//报数 
		int start=0;//起始人编号 
	    for(;num>i;){//总人数小于i时 
			start=(start+m-1)%num--;//每次报数结束时的人 
	        if(start<i){//起始报数人为好人 
				m++;//报数个数加一 
				num=2*i;//初始总人数 
	        	start=0;//初始起始人编号 
	        	continue;//进行下一次循环 
	        	}
	    	arr[i]=m;//打表赋值 
	    	}	
		}
	int k;
	while(scanf("%d",&k)!=EOF&&k){
		printf("%d\n",arr[k]);
	}
}
