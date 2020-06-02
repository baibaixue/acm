#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<cmath>
#define maxn 300005
#define inf 0x3f3f3f3f
using namespace std;
struct node{
	int to;
	int c,next;
}edge[maxn];
int level[maxn];
int head[maxn];
int S,T;
int tot;
char map1[25][25];
char map2[25][25];
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
	Q.push(S);
	level[S]=1;
	while(!Q.empty()){
		int a=Q.front();
		Q.pop();
		for(int i=head[a];i!=-1;i=edge[i].next){
			int b=edge[i].to;
			if(level[b]==0&&edge[i].c>0){
				level[b]=level[a]+1;
				Q.push(b);
			}
		}
	}
	return level[T]!=0;
}
int dfs(int s,int cp){
	int sumf=0;
	int f=0;
	if(s==T){
		return cp;
	}
	for(int i=head[s];i!=-1&&sumf<cp;i=edge[i].next){
		int b=edge[i].to;
		if(level[b]==level[s]+1&&edge[i].c>0){
			f=dfs(b,min(cp-sumf,edge[i].c));
			edge[i].c-=f;
			edge[i^1].c+=f;
			sumf+=f;
		}
	}
	if(sumf==0){
		level[s]=-1;
	}
	return sumf;
}
int dinic(){
	int ans=0;
	while(bfs()){
		ans+=dfs(S,inf);
	}
	return ans;
}
int main(){
	int CNT;
	scanf("%d",&CNT);
	for(int ti=1;ti<=CNT;ti++){
		int n,d,suml=0;
		tot=0;
		memset(head,-1,sizeof(head));
		memset(map1,0,sizeof(map1));
		memset(map2,0,sizeof(map2));
		scanf("%d%d",&n,&d);
		//getchar();
		for(int i=0;i<n;i++){
			scanf("%s",map1[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%s",map2[i]);
		}
		int m=strlen(map1[0]);
		S=0;T=2*n*m+1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map2[i][j]=='L'){
					addedge(S,i*m+j+1,1);
					suml++;
				}
				if(map1[i][j]!='0'){
					addedge(i*m+j+1,n*m+(i*m+j+1),map1[i][j]-'0');
				}
				if(i-d<0||i+d>=n||j-d<0||j+d>=m){
					addedge(n*m+(i*m+j+1),T,inf);
				}else{
					for(int k=i-d;k<=i+d;k++){
						for(int K=j-d;K<=j+d;K++){
							if(k>=0&&K>=0&&k<n&&K<m&&(k!=i||K!=j)){
								if(abs(k-i)+abs(K-j)<=d&&map1[k][K]!='0'){
									addedge(n*m+(i*m+j+1),k*m+K+1,inf);
								}
							}
						}
					}
				}
			}
		}
		int res=dinic();
		int ans=suml-res;
		//printf("%d\n",ans);
		if(ans==0){
			printf("Case #%d: no lizard was left behind.\n",ti);
		}else if(ans==1){
			printf("Case #%d: 1 lizard was left behind.\n",ti);
		}else{
			printf("Case #%d: %d lizards were left behind.\n",ti,ans);
		}
	}
	return 0;
}
