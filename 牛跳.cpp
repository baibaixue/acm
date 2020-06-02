#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define maxn 150005
using namespace std;
long long dp[maxn][2];
int s[maxn];
int main(){
	int p;
	while(scanf("%d",&p)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=p;i++){
			scanf("%d",&s[i]);
		}
		dp[1][0]=0;
		dp[1][1]=s[1];
		for(int i=2;i<=p;i++){
			dp[i][0]=dp[i-1][1]-s[i];
			dp[i][1]=dp[i-1][0]+s[i];
			dp[i][0]=max(dp[i-1][0],dp[i][0]);
			dp[i][1]=max(dp[i-1][1],dp[i][1]);
		}
		printf("%lld\n",max(dp[p][0],dp[p][1]));
	}
	return 0;
}
 
