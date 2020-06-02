#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 22
using namespace std;
char map[maxn][maxn];
int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int visit[maxn][maxn];
struct node{
	int x,y;
	int time;
};
int bfs(int n,int m,int sx,int sy){
	queue<node>Q;
	node now,next;
	now.x=sx;now.y=sy;
	visit[sx][sy]=1; 
	now.time=0;
	Q.push(now);
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		if(map[now.x][now.y]=='T'){
			return now.time;
		}else{
			for(int i=0;i<4;i++){
				next.x=now.x+step[i][0];
				next.y=now.y+step[i][1];
				next.time=now.time+1;
				if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n){
					if(map[next.x][next.y]!='*'&&visit[next.x][next.y]!=1){
						if(map[next.x][next.y]=='|'){
							next.x+=step[i][0];
							next.y+=step[i][1];
							if(next.time%2==0&&(i==2||i==3)){
								if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&map[next.x][next.y]!='*'&&visit[next.x][next.y]!=1){
									visit[next.x][next.y]==1;
									Q.push(next);
								}
							}else if(next.time%2==1&&(i==0||i==1)){
								if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&map[next.x][next.y]!='*'&&visit[next.x][next.y]!=1){
									visit[next.x][next.y]==1;
									Q.push(next);
								}
							}
							else{
								next.x=now.x;
								next.y=now.y;
								visit[next.x][next.y]==1;
								Q.push(next);
							}
						}else if(map[next.x][next.y]=='-'){
							next.x+=step[i][0];
							next.y+=step[i][1];
							if(next.time%2==1&&(i==2||i==3)){
								if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&map[next.x][next.y]!='*'&&visit[next.x][next.y]!=1){
									visit[next.x][next.y]==1;
									Q.push(next);
								}
							}else if(next.time%2==0&(i==0||i==1)){
								if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&map[next.x][next.y]!='*'&&visit[next.x][next.y]!=1){
									visit[next.x][next.y]==1;
									Q.push(next);
								}
							}
							else{
								next.x=now.x;
								next.y=now.y;
								visit[next.x][next.y]==1;
								Q.push(next);
							}
						}
						else{
							visit[next.x][next.y]==1;
							Q.push(next);
						}
					}
				}
			}
		}
	}
	return 0;
}
int main(){
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF){
		getchar();
		int sx,sy,tx,ty;
		memset(map,0,sizeof(map));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='T'){
					tx=i;ty=j;
				}if(map[i][j]=='S'){
					sx=i;sy=j;
				}
			}
			getchar();
		}
		memset(visit,0,sizeof(visit));
		int ans=bfs(m,n,sx,sy);
		printf("%d\n",ans);
	}
	return 0;
}
