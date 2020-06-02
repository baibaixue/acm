#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 105
using namespace std;
char map[maxn][maxn];
int visit[maxn][maxn];
int step[5][2]={{0,0},{1,0},{-1,0},{0,1},{0,-1}};
struct node{
	int x,y;
	int turn;
	int dir;
};
int bfs(int m,int n,int sx,int sy,int ex,int ey,int k){
	queue<node>Q;
	node last,next;
	last.x=sx;
	last.y=sy;
	int turn=0;
	int dir=0;
	Q.push(last);
	visit[last.y][last.x]=1;
	while(!Q.empty()){
		last=Q.front();
		Q.pop();
		if(last.x==ex&&last.y==ey&&last.turn<=k){
			return 1;
		}
		for(int i=1;i<5;i++){
			next.x=last.x+step[i][0];
			next.y=last.y+step[i][1];
			if(last.dir==0){
				next.dir=i;
				next.turn=0;
			}else if(last.dir==i){
				next.dir=last.dir;
				next.turn=last.turn; 
			}else{
				next.dir=i;
				next.turn=last.turn+1;
			}
			if(next.x>0&&next.x<=n&&next.y>0&&next.y<=m){
				if(map[next.y][next.x]=='.'&&visit[next.y][next.x]<=10&&next.turn<=k){
					Q.push(next);
					visit[next.y][next.x]++;
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
		int n,m;
		scanf("%d%d",&m,&n);
		getchar();
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		memset(visit,0,sizeof(visit));
		int k;
		scanf("%d",&k);
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=bfs(m,n,x1,y1,x2,y2,k);
		if(ans==0||map[y2][x2]=='*'){
			printf("no\n");
		}else{
			printf("yes\n");
		}
	}
	return 0;
}
