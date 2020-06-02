#include<cstdio>
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
#define maxn 25
using namespace std;
char map[maxn][maxn];
int visit[maxn][maxn];
int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct node{
	int x,y,t;
};
int m,n;
int check(int x,int y){
	if(x>=0&&x<m&&y>=0&&y<n){
		if(map[x][y]!='*'){
			return 1;
		}
	}
	return 0;
}
int Min; 
void bfs(int sx,int sy){
	queue<node>Q;
	node now,next;
	now.x=sx;now.y=sy;
	now.t=0;
	Q.push(now);
	visit[sx][sy]=1;
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		if(map[now.x][now.y]=='T'){
			if(Min>=now.t){
				Min=now.t;
			}
			continue;
		}
		for(int i=0;i<4;i++){
			next.x=now.x+step[i][0];
			next.y=now.y+step[i][1];
			next.t=now.t+1;
			if(check(next.x,next.y)){
				if(map[next.x][next.y]=='|'){
						next.x=next.x+step[i][0];
						next.y=next.y+step[i][1];
						if((next.t%2==1&&(i==0||i==1))||(next.t%2==0&&(i==2||i==3))){
							next.t++;
						}
				}if(map[next.x][next.y]=='-'){
					next.x=next.x+step[i][0];
					next.y=next.y+step[i][1];
						if((next.t%2==0&&(i==0||i==1))||(next.t%2==1&&(i==2||i==3))){
							next.t++;
						}
					}
				if(check(next.x,next.y)&&(visit[next.x][next.y]>next.t||visit[next.x][next.y]==0)){
					visit[next.x][next.y]=next.t;
					Q.push(next);
				}
			}
		}
	}
	return;
}

int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		int sx,sy;
		Min=100000;
		getchar();
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S'){
					sx=i;sy=j;
				}
			}
			getchar();
		}
		bfs(sx,sy);
		printf("%d\n",Min);
	}
	return 0;
}

