#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 105
using namespace std;
int map[maxn][maxn];
int visit[maxn][maxn];
int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct node{
	int x;int y;
	bool t;
};
int n,m;
void bfs(int x1,int y1){
	queue<node>Q;
	node a,b;
	a.x=x1;
	a.y=y1;
	a.t=true;
	Q.push(a);
	visit[x1][y1]=1;
	while(!Q.empty()){
		a=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			b.x=a.x+step[i][0];
			b.y=a.y+step[i][1];
			b.t=!a.t;
			if(b.x>0&&b.x<=n&&b.y>0&&b.y<=m){
				if(visit[b.x][b.y]==0){
					if(b.t==1){
						map[b.x][b.y]=1;
					}
					Q.push(b);
					visit[b.x][b.y]=1;
				}
			}
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		map[x1][y1]=1;
		bfs(x1,y1);
		if(map[x2][y2]==1){
			printf("Win\n");
		}else{
			printf("Lose\n");
		}
	}
	return 0;
}
