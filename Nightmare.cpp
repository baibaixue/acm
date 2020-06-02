#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 10
using namespace std;
int map[maxn][maxn];
int time[maxn][maxn];
int visit[maxn][maxn];
int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct node{
	int x,y,time;
};
int bfs(int n,int m,int sx,int sy){
	queue<node>Q;
	node now;
	now.x=sx,now.y=sy,now.time=6;
	Q.push(now);
	visit[sx][sy]=1;
	node next;
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		visit[now.x][now.y]++;
		if(map[now.x][now.y]==3){
			return 1;
		}
		for(int i=0;i<4;i++){
			next.x=now.x+step[i][0];
			next.y=now.y+step[i][1];
			next.time=now.time-1;
			if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m){
				if(map[next.x][next.y]!=0&&visit[next.x][next.y]<=2){
					if(next.time>0){
						if(map[next.x][next.y]==4){
							next.time=6;
						}
						Q.push(next);
						time[next.x][next.y]=time[now.x][now.y]+1;
					}
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
		memset(time,0,sizeof(time));
		memset(visit,0,sizeof(visit));
		int n,m;
		scanf("%d%d",&n,&m);
		int sx,sy;
		int ex,ey;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]==2){
					sx=i;
					sy=j;
				}
				if(map[i][j]==3){
					ex=i;
					ey=j;
				}
			}
		}
		if(bfs(n,m,sx,sy)==1){
			printf("%d\n",time[ex][ey]);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
