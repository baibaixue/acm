#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 1020
#define INF 0x3f3f3f3f
#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a
using namespace std;
int dp[maxn][maxn];
int S[maxn];
int E[maxn];
void floyed(int n){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dp[i][k]!=INF)
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	return ;
}

int main(){
	long long t,s,d;
	while(scanf("%lld%lld%lld",&t,&s,&d)!=EOF){
		memset(dp,INF,sizeof(dp));
		memset(S,0,sizeof(S));
		memset(E,0,sizeof(E));
		int n=0;
		for(int i=1;i<maxn;i++){
			dp[i][i]=0;
		}
		for(int i=1;i<=t;i++){
			int a,b,x;
			scanf("%d%d%d",&a,&b,&x);
			dp[a][b]=min(dp[a][b],x);
			dp[b][a]=dp[a][b];
			a=max(b,a);
			n=max(n,a);
		}
		for(int i=1;i<=s;i++){
			scanf("%d",&S[i]);
		}
		for(int i=1;i<=d;i++){
			scanf("%d",&E[i]);
		}
		floyed(n);
		long long  min_=INF;
		for(int i=1;i<=s;i++){
			for(int j=1;j<=d;j++){
				min_=min(min_,dp[S[i]][E[j]]);
			}
		}
		printf("%lld\n",min_);
	} 
	return 0;
}
