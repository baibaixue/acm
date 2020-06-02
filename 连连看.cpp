#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 1010
using namespace std;
int broad[maxn][maxn];
int visit[maxn][maxn];
int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
	int x,y;
	int road;
	int cnt;
};
int bfs(int n,int m,int x1,int y1,int x2,int y2){
	queue<node>Q;
	memset(visit,0,sizeof(visit));
	node now;
	node next;
	now.x=x1,now.y=y1;
	now.road=-1;
	now.cnt=0;
	Q.push(now);
	while(!Q.empty()){
		now=Q.front();
		visit[now.x][now.y]=1;
		Q.pop();
		if(now.x==x2&&now.y==y2){
			return 1;
		}else if((now.x!=x1||now.y!=y1)&&broad[now.x][now.y]!=0){
			continue;
		}
		for(int i=0;i<4;i++){
			next.x=now.x+step[i][0];
			next.y=now.y+step[i][1];
			next.road=i;
			next.cnt=now.cnt;
			if(!(now.road==next.road||now.road==-1)){
				next.cnt+=1;
			}
			if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m){
				if(next.cnt<=2&&visit[next.x][next.y]!=1){
					if(!(broad[next.x][next.y]!=0&&broad[next.x][next.y]!=broad[x2][y2])){
						Q.push(next);
					}
				} 
			} 
		}
	}
	return 0;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n!=0&&m!=0){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					scanf("%d",&broad[i][j]);
				}
			}
			int q;
			scanf("%d",&q);
			while(q--){
				int x1,y1,x2,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				if(broad[x1][y1]!=broad[x2][y2]||broad[x1][y1]==0){
					printf("NO\n");
				}else{
					if(bfs(n,m,x1,y1,x2,y2)==0){
						printf("NO\n");
					}else{
						printf("YES\n");
					}
				}
			}
		}
		else{
			break;
		}
	}
	return 0;
}
