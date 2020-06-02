#include<cstdio>
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 0x3f3f3f3f
#define maxn 220
using namespace std;
long long map[maxn][maxn];
long long dp[maxn][maxn];
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		memset(dp,inf,sizeof(dp));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%lld",&map[i][j]);
			}
		}
		int sx=n/2+1;
		for(int i=1;i<=n;i++){
			dp[m+1][i]=inf;
			dp[m+1][i]*=-1;
			if(i==sx){
				dp[m+1][i]=0;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]*=-1;
			}
		}
//		for(int i=1;i<=m+1;i++){
//			for(int j=1;j<=n;j++){
//				printf("%lld ",map[i][j]);
//			}
//			printf("\n");
//		} 
		for(int i=m;i>=1;i--){
			for(int j=1;j<=n;j++){
				for(int k=-2;k<=2;k++){
					if(j+k>=1&&j+k<=n){
						dp[i][j+k]=max(dp[i][j+k],dp[i+1][j]+map[i][j+k]);
					}
				}
			}	
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(dp[1][i]>ans){
				ans=dp[1][i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
