#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 25
using namespace std;
char map[maxn][maxn];
int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int visit[maxn][maxn][1030];
int n,m,t;
struct node{
	int x,y,time,key;
};
int bfs(int sx,int sy){
	queue<node>Q;
	node last,next;
	last.x=sx;last.y=sy;
	last.key=0;
	last.time=0;
	Q.push(last);
	visit[sx][sy][last.key]=1;
	while(!Q.empty()){
		last=Q.front();
		Q.pop();
		if(map[last.x][last.y]=='^'&&last.time<t){
			return last.time;
		}
		for(int i=0;i<4;i++){
			next.x=last.x+step[i][0];
			next.y=last.y+step[i][1];
			next.key=last.key;
			next.time=last.time+1;
			if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m){
				if(map[next.x][next.y]!='*'&&visit[next.x][next.y][next.key]!=1){
					if(map[next.x][next.y]=='.'||map[next.x][next.y]=='@'||map[next.x][next.y]=='^'){
					//	cout<<"(x,y):"<<next.x<<" "<<next.y<<" key:"<<next.key<<"time:"<<next.time<<endl;
						Q.push(next);
						visit[next.x][next.y][next.key]=1;
					}if(map[next.x][next.y]<='j'&&map[next.x][next.y]>='a'){
						int key=1<<(int)(map[next.x][next.y]-'a');
						if(visit[next.x][next.y][next.key|key]!=1){
						//	cout<<"(x,y):"<<next.x<<" "<<next.y<<" key:"<<next.key<<"time:"<<next.time<<endl;
							visit[next.x][next.y][next.key|key]=1;
							next.key=next.key|key;
							Q.push(next);
						}
					}if(map[next.x][next.y]<='J'&&map[next.x][next.y]>='A'){
						int key=1<<(int)(map[next.x][next.y]-'A');
						if(next.key&key){
						//	cout<<"(x,y):"<<next.x<<" "<<next.y<<" key:"<<next.key<<"time:"<<next.time<<endl;
							Q.push(next);
							visit[next.x][next.y][next.key]=1;
						}
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
		memset(visit,0,sizeof(visit));
		int ans=bfs(sx,sy);
		if(ans==0){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}

