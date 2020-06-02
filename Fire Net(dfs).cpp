#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char map[5][5];
int vis[5][5];
int visit[5][5]; 
int step[2][2]={{1,0},{0,1}};
int n;
int ans;
bool is_ok(int x,int y){
	if(map[x][y]=='X'){
		return false;
	}
	if(vis[x][y]==1){
		return false;
	}
	for(int k=x-1;k>=1;k--){
		if(map[k][y]=='X'){
			break;
		}
		if(vis[k][y]==1){
			return false;
		}
	}
	for(int k=x+1;k<=n;k++){
		if(map[k][y]=='X'){
			break;
		}
		if(vis[k][y]==1){
			return false;
		}
	}
	for(int k=y-1;k>=1;k--){
		if(map[x][k]=='X'){
			break;
		}
		if(vis[x][k]==1){
			return false;
		}
	}
	for(int k=y+1;k<=n;k++){
		if(map[x][k]=='X'){
			break;
		}
		if(vis[x][k]==1){
			return false;
		}
	}
	return true;
}
void dfs(int num){
	if(num>ans){
		ans=num;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(is_ok(i,j)==true){
				vis[i][j]=1;
				dfs(num+1);
				vis[i][j]=0;
			}
		} 
	}
	
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		getchar();
		memset(vis,0,sizeof(vis));
		memset(visit,0,sizeof(visit));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		dfs(0);
		printf("%d\n",ans);
	}
}
