#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#define maxn 22
using namespace std;
struct node{
	int x;
	int y;
};
char map[maxn][maxn];
int visit[maxn][maxn];
int step[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int w,h;
int bfs(int a,int b,int c,int d){
	queue<node> Q;
	node now;
	now.x=a;now.y=b;
	Q.push(now);
	visit[a][b]=1;
	int move=1;
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		node next;
		for(int i=0;i<4;i++){
			next.x=now.x+step[i][0];
			next.y=now.y+step[i][1];
			if(next.x>=0&&next.y>=0&&next.x<d&&next.y<c){
				if(visit[next.x][next.y]!=1){
					if(map[next.x][next.y]=='.'){
						Q.push(next);
						visit[next.x][next.y]=1;
						move++;
					}
				}
			}
		}
	}
	return move;
}

int main(){
	while(scanf("%d%d%*c",&w,&h)!=EOF&&w!=0&&h!=0){
		int startx,starty;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@'){
					startx=i;starty=j;
				}
			}
			scanf("%*c");
		}
		memset(visit,0,sizeof(visit));
		int num=bfs(startx,starty,w,h);
		printf("%d\n",num);
	}
	return 0;
} 
