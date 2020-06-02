#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 220
#define INF 0x3f3f3f
using namespace std;
int dp[maxn][maxn];
void floyed(int n){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
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
			int a,b,x;
			scanf("%d%d%d",&a,&b,&x);
			if(dp[a][b]>=x){
				dp[a][b]=x;
				dp[b][a]=x;
			}
		}
		floyed(n);
		int s,t;
		scanf("%d%d",&s,&t);
		if(s==t){
			printf("0\n");
		}else if(dp[s][t]==dp[maxn-1][maxn-1]){
			printf("-1\n");
		}else{
			printf("%d\n",dp[s][t]);
		}
	}
	return 0;
} 
