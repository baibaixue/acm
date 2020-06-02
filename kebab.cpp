#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define inf 0x3f3f3f3f
#define maxn 1500005
#define MM 1100
using namespace std;
struct node{
	int to,c,next;
}edge[maxn];
struct Node{
	int si,ei,ni,ti;
}p[220];
int head[MM];
int level[MM];
int time[MM];
int S,T;
int tot;
int sum;
int Min(int a,int b)    
{    
    return a<b?a:b;    
} 
int cmp(int a,int b){
	return a<b;
}
void addedge(int s,int t,int p){
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
	memset(level,0,sizeof(level));
	level[S]=1;
	Q.push(S);
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(int i=head[now];i!=-1;i=edge[i].next){
			int last=edge[i].to;
			if(level[last]==0&&edge[i].c>0){
				level[last]=level[now]+1;
				Q.push(last);
			}
		}
	}
	//printf("visit[%d]=%d\n",T,visit[T]);
	return level[T]!=0;
}
int dfs(int t,int F){
	if(t==T){
		return F;
	}
	int sumf=0,f;
	for(int i=head[t];i!=-1&&F;i=edge[i].next){
		int last=edge[i].to;
		if(level[last]==level[t]+1&&edge[i].c>0){
			f=dfs(last,min(edge[i].c,F-sumf));
			if(f>0){
				edge[i].c-=f;edge[i^1].c+=f;
				sumf+=f;
				if(sumf==F){
					break;
				}
			}
			else level[last]=-1;
		}
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
		int n,m;
		while(scanf("%d%d",&n,&m)!=EOF){
		tot=0;
		sum=0;
		S=0;
		int t=1;	
		memset(head,-1,sizeof(head));
		memset(time,0,sizeof(time));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&p[i].si,&p[i].ni,&p[i].ei,&p[i].ti);
			sum+=p[i].ni*p[i].ti;
			addedge(S,i,p[i].ni*p[i].ti);
			time[t++]=p[i].si;time[t++]=p[i].ei;
		}
		T=n+t+1;
		sort(time+1,time+1+t,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=t;j++){
				if(p[i].si<=time[j-1]&&p[i].ei>=time[j]){
					addedge(i,n+j,inf);
				}
			}
		}
		for(int i=1;i<=t;i++){
			addedge(n+i,T,(time[i]-time[i-1])*m);
		}
		//printf("%d\n%d\n",S,T);
		int res=dinic();
		//cout<<res<<endl;
		if(res>=sum){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
