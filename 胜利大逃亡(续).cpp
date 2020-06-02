#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#define maxn 22
using namespace std;
char map[maxn][maxn];
int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int visit[maxn][maxn];
int n,m,t;
struct node{
	int x,y,time;
	int key[10];
};
int bfs(int sx,int sy,int t){
	queue<node>Q;
	node last,next;
	last.x=sx;last.y=sy;
	last.time=0;
	memset(last.key,0,sizeof(last.key));
	Q.push(last);
	visit[sx][sy]++;
	while(!Q.empty()){
		last=Q.front();
		Q.pop();
		if(map[last.x][last.y]=='^'&&last.time<t){
			return last.time;
		}
		for(int i=0;i<4;i++){
			next.x=last.x+step[i][0];
			next.y=last.y+step[i][1];
			next.time=last.time+1;
			if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m){
				if(map[next.x][next.y]!='*'&&visit[next.x][next.y]<=40&&next.time<t){
					for(int k=0;k<10;k++){
						next.key[k]=last.key[k];
					}
					if(map[next.x][next.y]>='a'&&map[next.x][next.y]<='j'){
						next.key[(int)(map[next.x][next.y]-'a')]=1;
						Q.push(next);
						visit[next.x][next.y]++;
					}else if(map[next.x][next.y]>='A'&&map[next.x][next.y]<='J'){
						if(next.key[(int)(map[next.x][next.y]-'A')]==1){
							Q.push(next);
							visit[next.x][next.y]++;
						}
					}else{
						Q.push(next);
						visit[next.x][next.y]++;
					}
				}
			}
		}
	}
	return 0;
}
int main(){ 
	while(scanf("%d%d%d",&n,&m,&t)!=EOF){
		getchar();
		int sx,sy;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@'){
					sx=i;sy=j;
				}
			}
			getchar();
		}
		int ans=bfs(sx,sy,t);
		if(ans==0){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
} 
