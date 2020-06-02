#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#define maxn 55
using namespace std;
int map [maxn][maxn][maxn];
int espace_time [maxn][maxn][maxn];
//int escape_time [maxn][maxn][maxn];
int step[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct node{
	int x;
	int y;
	int z;
};
int bfs(int a,int b,int c){
	queue<node> Q;
	node now;
	now.x=0;now.y=0;now.z=0;
	Q.push(now);
	espace_time[now.x][now.y][now.z]=0;
	map[now.x][now.y][now.z]=1;
	while(!Q.empty()){
		now=Q.front();
		if(now.x==a-1&&now.y==b-1&&now.z==c-1){
			return espace_time[now.x][now.y][now.z];
		}
		Q.pop();
		node next;
		for(int i=0;i<6;i++){
			next.x=now.x+step[i][0];
			next.y=now.y+step[i][1];
			next.z=now.z+step[i][2];
			if(next.x>=0&&next.y>=0&&next.z>=0){
				if(map[next.x][next.y][next.z]==0){
					Q.push(next);
					espace_time[next.x][next.y][next.z]=espace_time[now.x][now.y][now.z]+1;
					map[next.x][next.y][next.z]=1;
					//cout<<"map["<<next.x<<"]["<<next.y<<"]["<<next.z<<"]="<<map[next.x][next.y][next.z]<<"\n";
					//cout<<"map["<<next.x<<"]["<<next.y<<"]["<<next.z<<"].time="<<next.time<<"\n";
				}
			}
		}
	}
	return -1;
}
int main(){
	int A,B,C;
	int k;
	scanf("%d",&k);
	int t;
	while(k--){
		scanf("%d%d%d",&A,&B,&C);
		scanf("%d",&t);
		memset(map,1,sizeof(map));
		for(int i=0;i<A;i++){
			for(int j=0;j<B;j++){
				for(int l=0;l<C;l++){
					scanf("%d",&map[i][j][l]);
				}
			}
		}
		//memset(escape_time,-1,sizeof(escape_time));
		int ans=bfs(A,B,C);
		if(ans>t||ans==-1){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}
