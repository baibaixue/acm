#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#define inf 0x3f3f3f3f
#define maxn 1005
using namespace std;
int c[maxn][maxn];//ÈÝÁ¿ 
int f[maxn][maxn];//²ÐÁ¿ 
int level[maxn];
bool visit[maxn];
int n,m;
bool bfs(int s,int t){
	memset(level,0,sizeof(level));
	queue<int>Q;
	Q.push(s);
	level[s]=1;
	int x;
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(int i=0;i<=500+n+1;i++){
			if(level[i]==0&&c[x][i]>f[x][i]){
				level[i]=level[x]+1;
				Q.push(i);
			}
		}
	}
	if(level[t]!=0){
		return true;
	}else{
		return false;
	}
} 
int dfs(int s,int x){
	int tmp=x;
	if(s==500+n+1){
		return tmp;
	}
	for(int i=0;i<=(500+n+1)&&tmp;i++){
		if(level[s]+1==level[i]){
			if(c[s][i]>f[s][i]){
				int d=dfs(i,min(tmp,c[s][i]-f[s][i]));
				f[s][i]+=d;
				f[i][s]-=d;
				tmp-=d;
			}	
		}
	}
	return x-tmp;
}
int dinic(int s,int t){
	int ans;
	while(bfs(s,t)){
		int a=dfs(0,inf);
		while(a){
			ans+=a;
			a=dfs(0,inf);
		}
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		memset(c,0,sizeof(c));
		int a,s,e;
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&s,&e);
			sum+=a;
			c[0][i]=a;
			for(int j=s;j<=e;j++){
				c[i][n+j]=1;
				c[n+j][500+n+1]=m;
			}
		}
		int res=dinic(0,500+n+1);
		//printf("%d\n",res);
		if(res>=sum){
			printf("Case %d: Yes\n",T);
		}else{
			printf("Case %d: No\n",T);
		}
	}
	return 0;
} 
