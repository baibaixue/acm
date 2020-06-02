#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<string.h>
#define maxn 10
using namespace std;
int map[maxn][maxn];
int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int m,n;
struct node{
	int x,y;
};
struct _node{
	int x,y,p_x,p_y;
	int steps;
};
int visit[maxn][maxn];
int move(int sx,int sy,int ex,int ey,int cx,int cy){
	memset(visit,0,sizeof(visit));
	queue<node>Q;
	node last,next;
	last.x=sx;
	last.y=sy;
	Q.push(last);
	visit[sx][sy]=1;
	while(!Q.empty()){
		last=Q.front();
		Q.pop();
		if(last.x==ex&&last.y==ey){
			return 1;
		}
		for(int i=0;i<4;i++){
			next.x=last.x+step[i][0];
			next.y=last.y+step[i][1];
			if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&(next.x!=cx||next.y!=cy)){
				if(map[next.x][next.y]!=1&&visit[next.x][next.y]!=1){
					//printf("last(x,y)=(%d,%d) next(x,y)=(%d,%d)\n",last.x,last.y,next.x,next.y);
					Q.push(next);
					visit[next.x][next.y]=1;
//					for(int a=0;a<m;a++){
//						for(int b=0;b<m;b++){
//							printf("%d",visit[a][b]);
//						}
//						printf("\n");
//					}
				}
			}
		}
	}
	return 0;
}
int _visit[maxn][maxn];
int bfs(int px,int py,int cx,int cy){
	queue<_node>Q;
	_node last,next;
	last.x=cx,last.y=cy;
	last.p_x=px,last.p_y=py;
	last.steps=0;
	Q.push(last);
	_visit[cx][cy]=1; 
	while(!Q.empty()){
		last=Q.front();
		Q.pop();
		if(map[last.x][last.y]==3){
			int s=last.steps;
			return s;
		}
		for(int i=0;i<4;i++){
			next.x=last.x+step[i][0];
			next.y=last.y+step[i][1];
			if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&(last.x-step[i][0])>=0&&(last.x-step[i][0])<m&&(last.y-step[i][1])>=0&&(last.y-step[i][1])<n){
				if(map[next.x][next.y]!=1&&map[last.x-step[i][0]][last.y-step[i][1]]!=1){
					if(_visit[next.x][next.y]<=4&&move(last.p_x,last.p_y,last.x-step[i][0],last.y-step[i][1],last.x,last.y)==1){
						next.p_x=last.x-step[i][0];
						next.p_y=last.y-step[i][1];
						next.steps=last.steps+1;
						Q.push(next);
						//printf("箱子(x,y):(%d,%d) 人物(x,y):(%d,%d) 目前步数：%d\n",next.x,next.y,next.p_x,next.p_y,next.steps);
						_visit[next.x][next.y]++;
//						for(int a=0;a<m;a++){
//							for(int b=0;b<m;b++){
//								printf("%d",_visit[a][b]);
//							}
//						printf("\n");
//					}
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
		scanf("%d%d",&m,&n);
		int px,py;
		int cx,cy;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]==4){
					px=i;py=j;
				}else if(map[i][j]==2){
					cx=i;cy=j;
				}
			}
		}
		int ans;
		memset(_visit,0,sizeof(_visit));
		ans=bfs(px,py,cx,cy);
		if(ans==0){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}
