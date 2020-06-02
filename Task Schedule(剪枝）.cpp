#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define inf 0x3f3f3f3f
#define maxn 200005
#define MM 1010
using namespace std;
struct node{
	int to,c,next;
}edge[maxn];
int head[MM];
int level[MM],visit[MM];
int S,T;
int tot;
int sum;
void inline addedge(int s,int t,int p){
	edge[tot].to=t;
	edge[tot].c=p;
	edge[tot].next=head[s];
	head[s]=tot++;
	
	edge[tot].to=s;
	edge[tot].c=0;
	edge[tot].next=head[t];
	head[t]=tot++;
}
bool bfs(){
	queue<int>Q;
	for(int i=0;i<MM;i++){
		visit[i]=level[i]=0;
	}
	//printf("in bfs S=%d\nnow=%d\n",S,now);
	visit[S]=1;
	level[S]=1;
	Q.push(S);
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(int i=head[now];i!=-1;i=edge[i].next){
			int last=edge[i].to;
			//printf("%d\n",last);
			if(visit[last]==0&&edge[i].c>0){
				level[last]=level[now]+1;
				visit[last]=1;
				Q.push(last);
			}
		}
	}
	//printf("visit[%d]=%d\n",T,visit[T]);
	return visit[T];
}
int dfs(int t,int F){
	if(t==T||F==0){
		return F;
	}
	int sumf=0,f;
	for(int i=head[t];i!=-1&&F;i=edge[i].next){
		int last=edge[i].to;
		if(level[last]==level[t]+1&&edge[i].c>0){
			f=dfs(last,min(edge[i].c,F));
			edge[i].c-=f;edge[i^1].c+=f;
			sumf+=f;
			F-=f;
		}
	}
	if(sumf==0){
		level[t]=-1;
	}
	return sumf;
}
int dinic(){
	int ans=0;
	//printf("in dinic S=%d\n",S);
	while(bfs()){
		ans+=dfs(S,inf);
	}
	return ans;
}
int main(){
	int Ti;
	scanf("%d",&Ti);
	for(int t=1;t<=Ti;t++){
		int n,m;
		scanf("%d%d",&n,&m);
		tot=0;
		sum=0;
		S=n+501;T=n+502;	
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++){
			int pi,s,e;
			scanf("%d%d%d",&pi,&s,&e);
			sum+=pi;
			addedge(S,i,pi);
			for(int j=s;j<=e;j++){
				addedge(i,n+j,1);
			}
		}
		for(int i=1;i<=500;i++){
			addedge(n+i,T,m);
		}
		//printf("%d\n%d\n",S,T);
		int res=dinic();
		//cout<<res<<endl;
		if(res==sum){
			printf("Case %d: Yes\n\n",t);
		}else{
			printf("Case %d: No\n\n",t);
		}
	}
	return 0;
}
