#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 1005
#define inf 0x3f3f3f3f
using namespace std;
int dp[maxn];
int link[maxn][maxn];
int visit[maxn];
void spfa(int n,int s){
	queue<int>Q;
	Q.push(s);
	visit[s]=1;
	int a;
	while(!Q.empty()){
		a=Q.front();
		Q.pop();
		visit[a]=0;
		for(int k=1;k<=n;k++){
			if(link[a][k]!=inf&&(dp[a]+link[a][k])<=dp[k]){
				dp[k]=dp[a]+link[a][k];
				if(visit[k]==0){
					visit[k]=1;
					Q.push(k);
				}
			}
		}
	}
	return ;
}
int main(){
	int n,m,s;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF){
		memset(dp,inf,sizeof(dp));
		memset(link,inf,sizeof(link));
		memset(visit,0,sizeof(visit));
		dp[s]=0;
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			link[b][a]=min(link[b][a],c);
			//link[b][a]=link[a][b];
		}
		spfa(n,s);
		int w,x;
		int ans=inf;
		scanf("%d",&w);
		for(int i=0;i<w;i++){
			scanf("%d",&x);
			ans=min(dp[x],ans);
		}
		if(ans==inf){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}
