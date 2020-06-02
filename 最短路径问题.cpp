#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string.h>
#define maxn 1005
#define inf 0x3f3f3f3f
using namespace std;
int dp[maxn];
int dd[maxn];
int D[maxn][maxn];
int P[maxn][maxn];
int visit[maxn];
int n,m;
void spfa(int n,int s){
	queue<int>Q;
	int a=s;
	Q.push(a);
	visit[a]=1;
	while(!Q.empty()){
		a=Q.front();
		Q.pop();
		visit[a]=0;
		for(int i=1;i<=n;i++){
			if(D[i][a]!=inf){
				if(dd[i]>dd[a]+D[a][i]){
					dd[i]=dd[a]+D[a][i];
					dp[i]=dp[a]+P[a][i];
					if(visit[i]!=1){
						Q.push(i);
						visit[i]=1;
					}
				}if(dd[i]==dd[a]+D[a][i]){
					if(dp[i]>dp[a]+P[a][i]){
						dd[i]=dd[a]+D[a][i];
						dp[i]=dp[a]+P[a][i];
						if(visit[i]!=1){
							Q.push(i);
							visit[i]=1;
						}
					}
				}
			}
		}
	}
	return ;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF&&(n!=0||m!=0)){
		memset(D,inf,sizeof(D));
		memset(P,inf,sizeof(P));
		memset(dp,inf,sizeof(dp));
		memset(dd,inf,sizeof(dd));
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=n;i++){
			D[i][i]=0;
			P[i][i]=0;
		}
		for(int i=0;i<m;i++){
			int a,b,d,p;
			scanf("%d%d%d%d",&a,&b,&d,&p);
			if(D[a][b]>d){
				D[a][b]=d;D[b][a]=d;P[a][b]=p;P[b][a]=p;
			}else if(D[a][b]==d&&P[a][b]>p){
				D[a][b]=d;D[b][a]=d;P[a][b]=p;P[b][a]=p;
			}
		}
		int s,t;
		scanf("%d%d",&s,&t);
		dp[s]=0;
		dd[s]=0;
		spfa(n,s);
		printf("%d %d\n",dd[t],dp[t]);
	}
	return 0;
}
