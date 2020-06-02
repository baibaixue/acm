#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1010
using namespace std;
long long int V[maxn];
long long int M[maxn];
long long int dp[maxn][maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,bag_v;
		scanf("%d%d",&n,&bag_v);
		for(int i=1;i<=n;i++){
			scanf("%lld",&M[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&V[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int v=0;v<=bag_v;v++){
				if(i==1){
					dp[i][v]=0;
					//printf("dp[%d][%d]=%d\n",i,v,dp[i][v]);
				}else{
					dp[i][v]=dp[i-1][v];
					//printf("dp[%d][%d]=%d\n",i,v,dp[i][v]);
				} 
				if(v>=V[i]){
					dp[i][v]=max(dp[i-1][v],dp[i-1][v-V[i]]+M[i]);
					//printf("dp[%d][%d]=%d\n",i,v,dp[i][v]);
				}
			}
		}
		printf("%lld\n",dp[n][bag_v]);
	}
	return 0;
} 
