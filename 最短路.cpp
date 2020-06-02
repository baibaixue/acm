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
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0){
		memset(dp,inf,sizeof(dp));
		int a,b,c;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			dp[a][b]=c;
			dp[b][a]=c;
		}
		floyd(n);
		printf("%d\n",dp[1][n]);
	}
	return 0;
}
