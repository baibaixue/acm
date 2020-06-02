#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 25
#define inf 0x3f3f3f3f
using namespace std;
struct node{
	int c;
	int t;
	int x,y;
};
char map[maxn][maxn];
int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int visit[maxn][maxn][26][100];
int ans;
void bfs(int m,int n){
	queue<node>Q;
	node a,b;
	a.x=0;
	a.t=0;
	a.c=-1;
	for(int i=1;i<=n;i++){
		a.y=i;
		Q.push(a);
	}
	while(!Q.empty()){
		a=Q.front();
		if(a.x==m+1){
			if(a.t<ans){
				ans=a.t;
				continue;
			}
		}
		Q.pop();
		for(int i=0;i<4;i++){
			b.x=a.x+step[i][0];
			b.y=a.y+step[i][1];
			b.t=a.t;
			if(b.x>=1&&b.y>=1&&b.y<=n&&b.x<=m+1){
				b.c=map[b.x][b.y]-'A';
				if(b.c!=a.c&&a.c!=-1){
					b.t=a.t+1;
				}
				if(visit[b.x][b.y][b.c][b.t]!=1){
					Q.push(b);
					visit[b.x][b.y][b.c][b.t]=1;
				}
			}
		}
	}
	return ;
}
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		getchar();
		ans=inf;
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		bfs(m,n);
		printf("%d\n",ans);
	}
	return 0;
}
