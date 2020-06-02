#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 105
#define inf 0x3f3f3f3f
using namespace std;
int dp[maxn][maxn];
void floyd(int n){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	return ;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(dp,inf,sizeof(dp));
		for(int i=1;i<=n+2;i++){
			for(int j=1;j<=n+2;j++){
				scanf("%d",&dp[i][j]);
			}
		}
		floyd(n+2);
		printf("%d\n",dp[1][n+2]);
	}
	return 0;
}
