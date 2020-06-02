#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10
using namespace std;
int map[maxn][maxn];
int steps[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans=0;
int N,M;
int sx,sy,ex,ey;
void dfs(int x,int y){
	if(x==ex&&y==ey){
		ans++;
		return ;
	}
	int a,b;
	for(int i=0;i<4;i++){
		a=x+step[i][0];
		b=y+step[i][1];
		if(a>=0&&a<N&&b>=0&&b<M){
			if(dfs(a,b)!=0){
				map[x][y]
			} 
			
		}
	}
}
int main(){
	memset(map,0,sizeof(map));
	scanf("%d%d",&N,&M);
	int t;
	scanf("%d",&t);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	int x,y;
	for(int i=0;i<t;i++){
		scanf("%d%d",&x,&y);
		map[x][y]=1;
	}
} 
