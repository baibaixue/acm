#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 110
#define INF 0x3f3f3f
using namespace std;
int dp[maxn][maxn];
void floved(int n){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=min(dp[i][k]+dp[k][j]+1,dp[i][j]);
				dp[j][i]=dp[i][j];
			}
		}
	}
	return ;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(dp,INF,sizeof(dp));
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			dp[a][b]=0;
			dp[b][a]=0;
		}
		floved(n);
		int ok=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j&&dp[i][j]>6){
					ok=0;
					break;
				}
			}
		}
		if(ok==1){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
