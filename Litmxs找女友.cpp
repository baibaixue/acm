#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 505
using namespace std;
int times[maxn][maxn];
char map[maxn][maxn];
int visit[maxn][maxn];
int steps[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
struct move{
	int x,y;
};
int bfs(int n,int m){
	queue<move> Q;
	move a;
	a.x=0;
	a.y=0;
	Q.push(a);
	visit[0][0]=1;
	while(!Q.empty()){
		a=Q.front();
		//printf("%d %d\n",a.x,a.y);
		Q.pop();
		if(a.x==n-1&&a.y==m-1){
			return times[a.x][a.y];
		}
		for(int i=0;i<4;i++){
			move b;
			b.x=a.x+steps[i][0];
			b.y=a.y+steps[i][1];
			//printf("%d %d\n",b.x,b.y);
			if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m){
				if(visit[b.x][b.y]!=1&&map[b.x][b.y]=='.'){
					Q.push(b);
					visit[b.x][b.y]=1;
					times[b.x][b.y]=times[a.x][a.y]+1;
					//printf("time[%d][%d]=%d\n",b.x,b.y,times[b.x][b.y]);
				}
			}
		}
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		getchar();
		memset(times,0,sizeof(times));
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n;i++){
			scanf("%s",map[i]);
		}
//		for(int i=0;i<n;i++){
//			for(int j=0;j<m;j++){
//				cout<<map[i][j];
//			}
//			printf("\n");
//		}
		printf("%d\n",bfs(n,m));
	}
	return 0;
}
