#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<queue>
#define maxn 25
using namespace std;
int map[maxn][maxn];
int visit[maxn][maxn];
int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
	int x;
	int y;
};
int ans;
int w,h;
void bfs(int sx,int sy){
	queue<node>Q;
	node a;
	a.x=sx,a.y=sy;
	visit[sx][sy]=1;
	Q.push(a);
	while(!Q.empty()){
		a=Q.front();
		Q.pop();
		node b;
		for(int i=0;i<4;i++){
			b.x=a.x+step[i][1];
			b.y=a.y+step[i][0];
			if(b.x>0&&b.x<=h&&b.y>0&&b.y<=w){
				if(visit[b.x][b.y]==0&&map[b.x][b.y]=='.'){
					Q.push(b);
					ans++;
					visit[b.x][b.y]=1;
				}
			}
		}
	}
	return ;
}
int main(){
	while(scanf("%d%d",&w,&h)!=EOF){
		int sx;int sy;
		getchar();
		ans=0;
		memset(visit,0,sizeof(visit));
		memset(map,0,sizeof(map));
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@'){
					sx=i;sy=j;
					ans++;
				}
			}
			getchar();
		}
		bfs(sx,sy);
		printf("%d\n",ans);
	}
	return 0;
}
