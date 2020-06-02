#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#define maxn 55
#define inf 0x3f3f3f3f
using namespace std;
char map[maxn][maxn];
int visit[maxn][maxn][50];
int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct node{
	int x,y;
	int num;
	int high;
	int pump;
};
int ans;
int bfs(int n,int m){
	queue<node>Q;
	node a,b;
	a.high=(int)(map[1][1]-'a');
	a.num=1;
	a.pump=0;
	a.x=1;b.x=1;
	visit[1][1][0]=1;
	map[1][1]='0';
	Q.push(a);
	while(!Q.empty()){
		if(a.num==n*m){
			if(ans>a.pump){
				ans=a.pump;
			}
		}
		a=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			b.x=a.x+step[i][0];
			b.y=a.y+step[i][0];
			if(b.x>0&&b.x<=n&&b.y>0&&b.y<=m){
				if(map[b.x][b.y]-'a'<=a.high){
					b.high=map[b.x][b.y]-'a';
					b.pump=a.pump;
				}else if(map[b.x][b.y]-'a'>a.high){
					b.high=map[b.x][b.y]-'a';
					b.pump=a.pump+1;
				}if(visit[b.x][b.y][b.pump]!=1){
					b.num=a.num+1;
					Q.push(b);
					visit[b.x][b.y][b.pump]=1;
				}
			}
		}
	}
	return 0;
}
int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		int n,m;
		ans=inf;
		memset(visit,0,sizeof(visit));
		scanf("%d%d",&n,&m);
		getchar();
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		bfs(n,m);
		printf("%d\n",ans);
	}
	return 0;
}
