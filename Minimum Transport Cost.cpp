#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define maxn 1005
#define INF 0x3f
int trans[maxn][maxn];
int tax[maxn];
int pre[maxn][maxn];
int dp[maxn][maxn];
void DP(int a,int b,int n){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][j]>dp[i][k]+dp[k][j]+tax[k]){
					dp[i][j]=dp[i][k]+dp[k][j]+tax[k];
					pre[i][j]=pre[i][k];
				}
				if(dp[i][j]==dp[i][k]+dp[k][j]+tax[k]){
					if(pre[i][j]>pre[i][k]){
						dp[i][j]=dp[i][k]+dp[k][j]+tax[k];
						pre[i][j]=pre[i][k];
					}
				}
				//printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
			//	printf("pre[%d][%d]=%d\n",i,j,pre[i][j]);
			}
		}
	return ;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&dp[i][j]);
				pre[i][j]=j;
				if(dp[i][j]==-1){
					dp[i][j]=INF;
				}
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&tax[i]);
		}
		int a,b;
		while(scanf("%d%d",&a,&b)&&a!=-1&&b!=-1){
			DP(a,b,n);
			printf("From %d to %d :\nPath: ",a,b);
			int x=a,y=b;
			while(x!=y){
				printf("%d-->",x);
				x=pre[x][y];
			}
			printf("%d\n",b);
			printf("Total cost : %d\n\n",dp[a][b]);
		}
	}
	return 0;
}
