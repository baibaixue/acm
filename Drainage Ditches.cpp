#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#define inf 0x3f3f3f3f
#define maxn 220
using namespace std;
int c[maxn][maxn];
bool visit[maxn];
int pre[maxn];
int n,m;
bool bfs(int s,int t){
	queue<int>Q;
	memset(visit,0,sizeof(visit));
	memset(pre,-1,sizeof(pre));
	Q.push(s);
	visit[s]=true;
	pre[s]=s;
	int p;
	while(!Q.empty()){
		p=Q.front();
		Q.pop();
		for(int i=1;i<=m;i++){
			if(c[p][i]>0&&visit[i]!=true){
				pre[i]=p;
				visit[i]=true;
				if(i==t){
					return true;
				}
				Q.push(i);
			}
		}
	}
	return false;
}
int EK(int s,int t){
	int ans=0;
	int minn;
	while(bfs(s,t)==1){
		minn=inf;
		for(int i=t;i!=s;i=pre[i]){
			if(minn>c[pre[i]][i]){
				minn=c[pre[i]][i];
			}
		}
		for(int i=t;i!=s;i=pre[i]){
			c[pre[i]][i]-=minn;
			c[i][pre[i]]+=minn;
		}
		ans+=minn;
	}
	return ans;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(c,0,sizeof(c));
		int a,b,d;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&d);
			c[a][b]+=d;
		}
		printf("%d\n",EK(1,m));
	}
	return 0;
} 
