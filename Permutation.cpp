#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<algorithm>
#define maxn 100005
#define mod 1000000007
using namespace std;
long long num[maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&num[i]);
		}
		sort(num,num+n);
		long long ans=1;
		for(int i=0;i<n;i++){
			ans=ans*(num[i]-i);
			ans=ans%mod;
		}
		printf("%lld\n",ans);
	}
} 
