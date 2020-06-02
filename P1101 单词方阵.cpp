#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 105
using namespace std;
char map[maxn][maxn];
int visit[maxn][maxn];
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const char word[]="yizhong";
int ans[maxn][maxn];
int dfs(int k,int x,int y,int n,int d){
	if(k>=7){
		return 1;
	}
	else if((x>n||y>n||x<0||y<0)){
		return 0;
	}
	if(map[x][y]==word[k]){
		ans[x][y]++;
	//	printf("ans[%d][%d]=%d\n",x,y,ans[x][y]);
//		visit[x][y]++;
	if(dfs(k+1,x+dir[d][0],y+dir[d][1],n,d)==0){
//		if(visit[x][y]==1){
			ans[x][y]--;
//			visit[x][y]--;
			return 0;
		//	}
		}
	}else{
		return 0;	
	}
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j]; 
		}
		getchar();
	}
	memset(ans,0,sizeof(ans));
	//memset(visit,0,sizeof(visit));
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			for(int i=0;i<7;i++){
				dfs(0,x,y,n,i);
			}
		}  
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ans[i][j]!=0){
				printf("%c",map[i][j]);
			}else{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
