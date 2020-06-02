#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#define maxn 110
using namespace std;
char map[maxn][maxn];
int visit[maxn][maxn][5][3];
int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct node{
	int x,y;
	int dir;
	int turn;
};
int bfs(int m,int n,int sx,int sy,int ex,int ey,int k){
	queue<node>Q;
	node now,next;
	now.x=sx;now.y=sy;
	now.dir=4;now.turn=0;
	Q.push(now);
	visit[sy][sx][4][0]=1;
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		if(now.x==ex&&now.y==ey&&now.turn<=k){
			return 1;
		}
		for(int i=0;i<4;i++){
			next.x=now.x+step[i][0];
			next.y=now.y+step[i][1];
			if(now.dir==4){
				next.dir=i;
				next.turn=now.turn;
			}else if(now.dir==i){
				next.dir=i;
				next.turn=now.turn;
			}else{
				next.turn=now.turn+1;
				next.dir=i;
			}
			if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m){
				if(map[next.y][next.x]=='.'&&visit[next.y][next.x][next.dir][next.turn]!=1&&next.turn<=k){
					Q.push(next);
					visit[next.y][next.x][next.dir][next.turn]=1;
				}
			}
		}
	}
	return 0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		int m,n;
		scanf("%d%d",&m,&n);
		getchar();
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		int k,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&k,&x1,&y1,&x2,&y2);
		int ans=bfs(m,n,x1,y1,x2,y2,k);
		if(ans==0){
			printf("no\n");
		}else{
			printf("yes\n");
		}
	}
	return 0;
}
