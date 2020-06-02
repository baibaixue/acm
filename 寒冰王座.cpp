#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int cost[3]={150,200,350};
int dp[10010];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int N;
		scanf("%d",&N);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<3;i++){
			for(int j=cost[i];j<=N;j++){
				dp[j]=max(dp[j],dp[j-cost[i]]+cost[i]);
				//printf("dp[%d]=%d\n",j,dp[j]);
			}
		}
		printf("%d\n",N-dp[N]);
	}
	return 0;
}
