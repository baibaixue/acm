#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<string.h>
#define maxn 2005
using namespace std;
int n,m;
int map[maxn][maxn];
int Time[maxn][maxn];
int visit[maxn][maxn];
struct node{
	int x;
	int y;
	int is_ok;
};
const int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
node start;
//node ne_xt;
int bfs(node start,node end){
	queue<node> Q;
	Q.push(start);
	visit[start.x][start.y]=1;
	while(!Q.empty()){
		struct node a,b;
		a=Q.front();
		Q.pop();
		if(map[a.x][a.y]==2){
			a.is_ok=1;
		}
		if(map[a.x][a.y]==3&&a.is_ok==1){
			return Time[a.x][b.x];
		}
		for(int i=0;i<4;i++){
			b.x=a.x+step[i][0];
			b.y=a.y+step[i][1];
			if(a.is_ok==1){
				b.is_ok=1;
			}else{
				b.is_ok=0;
			}
			if(b.x>=0&&b.x<=n&&b.y>=0&&b.y<=m){
				if((b.is_ok==0&&visit[b.x][b.y]==0)||(b.is_ok==1&&visit[b.x][b.y]!=2)&&map[b.x][b.y]!=0){
					Q.push(b);
					visit[b.x][b.y]++;
					Time[b.x][b.y]=Time[a.x][a.y]+1;
				}
			}
		}
	}
	return 0;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		getchar();
		char c;
		memset(visit,0,sizeof(visit));
		memset(Time,0,sizeof(Time));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%c",&c);
				if(c=='#'){
					map[i][j]=0;
				}else if(c=='.'){
					map[i][j]=1;
				}else if(c=='L'){
					map[i][j]=1;
					start.x=i;
					start.y=j;
					start.is_ok=0;
				}else if(c=='W'){
					map[i][j]=2;
				}else if(c=='Q'){
					map[i][j]=3;
				}
			}
			getchar();
		}
		//bfs(start,2);
		//memset(visit,0,sizeof(visit));
		int ans=bfs(start);
		printf("%d\n",ans); 
	}
	return 0;
}
