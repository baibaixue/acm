#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn  1000005
using namespace std;
int a[maxn];
int first[maxn];
int main(){
	long long n,k;
	int mm=0;
	while(scanf("%lld%lld",&n,&k)!=EOF){
		memset(a,0,sizeof(a));
		memset(first,0,sizeof(first));
		for(int i=1;i<=n;i++){
			long long x;
			scanf("%lld",&x);
			a[x]++;
			if(first[x]==0){
				first[x]=i;
			}
			if(x>=mm){
				mm=x;
			}
		}
		long long min_rank=maxn;
		long long ans=0;
		for(int i=0;i<=mm;i++){
			if(a[i]==k){
				if(first[i]<min_rank){
					min_rank=first[i];
					ans=i;
				}
			}
		}
		if(min_rank==maxn){
			printf("-1\n");
		}else{
			printf("%lld\n",ans);
		}
	}
} 
