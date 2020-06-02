#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 120
#define inf 0x3f3f3f3f
using namespace std;
int d[maxn];
int c[maxn][maxn];
int dp[100000];
int p[maxn];
bool vis[maxn];
void spfa(int n){
	for(int i=0;i<=n;i++){
		d[i]=inf;vis[i]=0;
	}
	queue<int>Q;
	Q.push(0);
	d[0]=0;
	vis[0]=true;
	int a;
	while(!Q.empty()){
		a=Q.front();
		Q.pop();
		vis[a]=false;
		for(int i=0;i<=n;i++){
			if(c[a][i]!=inf){
				if(d[i]>d[a]+c[a][i]){
					d[i]=d[a]+c[a][i];
					if(vis[i]!=1){
						Q.push(i);
						vis[i]=true;
					}
				}
			}
		}
	}
	return ;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				c[i][j]=inf;
			}
			c[i][i]=0;
		}
		for(int i=0;i<m;i++){
			int a,b,x;
			scanf("%d%d%d",&a,&b,&x);
			if(c[a][b]>x){
				c[a][b]=x;
				c[b][a]=x;
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			sum+=p[i];
		}
		for(int i=0;i<=sum;i++){
			dp[i]=inf;
		}
		dp[0]=0;
		spfa(n);
		for(int i=1;i<=n;i++){
			for(int j=sum;j>=p[i];j--){
				dp[j]=min(dp[j-p[i]]+d[i],dp[j]);
			}
		}
		int ans=inf;
		for(int i=sum/2+1;i<=sum;i++){
			ans=min(ans,dp[i]);
		}
		if(ans>=inf){
			printf("impossible\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}
