#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
long long num[100005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(num,0,sizeof(num));
		int n;
		scanf("%d",&n);
		long long maxnum=0;
		long long minnum=inf;
		int x=0;
		long long midnum=inf;
		int y=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&num[i]);
			if(num[i]>maxnum){
				maxnum=num[i];
			}
			if(num[i]<minnum){
				minnum=num[i];
				x=i;
			}
			if(num[i]<=midnum&&num[i]>=minnum&&i!=x){
				midnum=num[i];
				y=i;
			}
		}
		long long res=0;
		for(int i=0;i<n;i++){
			res+=maxnum-num[i];
		}
		if(midnum-res>=1){
			printf("%lld\n",res);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
