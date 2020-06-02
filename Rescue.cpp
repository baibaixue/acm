#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#define maxn 205
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
	node last,next;
	last.x=sx;
	last.y=sy;
	last.time=0; 
	visit[sx][sy]=1;
	Q.push(last);
	while(!Q.empty()){
		last=Q.front();
		Q.pop();
		if(map[last.x][last.y]=='r'){
			return last.time;
		}
		for(int i=0;i<4;i++){
			next.x=last.x+step[i][0];
			next.y=last.y+step[i][1];
			next.time=last.time+1; 
			if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m){
				if(map[next.x][next.y]!='#'&&visit[next.x][next.y]==0){
					if(map[next.x][next.y]=='x'){
						map[next.x][next.y]='.';
						next.x=last.x;
						next.y=last.y;
					}
					Q.push(next);
					visit[next.x][next.y]=1;
				}
			}
		}
	}
	return 0;
}
int main(){
	int n,m;
	int sx,sy;
	while(scanf("%d%d",&n,&m)!=EOF){
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='a'){
					sx=i;sy=j;
				}
			}
			getchar();
		}
		memset(visit,0,sizeof(visit));
		int ans=bfs(n,m,sx,sy);
		if(ans==0){
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}
