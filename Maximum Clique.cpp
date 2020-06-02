#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 60
using namespace std;
int map[maxn][maxn];
int Max[maxn];
int a[maxn][maxn];
int ans;
int n;
int dfs(int cnt,int tot){
	if(cnt==0){
		if(tot>ans){
			ans=tot;
			return 1;
		}
		return 0;
	}
	for(int i=0;i<cnt;i++){
		if(cnt-i+tot<=ans){
			return 0;
		}
		int u=a[tot][i];
		if(Max[u]+tot<=ans){
			return 0;
		}
		int next=0;
		for(int j=i+1;j<cnt;j++){
			if(map[u][a[tot][j]]==1){
				a[tot+1][next++]=a[tot][j];
			}
		}
		if(dfs(next,tot+1)){
			return 1;
		}
	}
	return 0;
}
int MaxClique(){
	ans=0;
	memset(Max,0,sizeof(Max));
	for(int i=n-1;i>=0;i--){
		int cnt=0;
		for(int j=i+1;j<n;j++){
			if(map[i][j]==1){
				a[1][cnt++]=j;
			}
		}
		dfs(cnt,1);
		Max[i]=ans;
	}
	return ans;
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		memset(map,0,sizeof(map));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&map[i][j]);
			}
		}
		printf("%d\n",MaxClique());
	}
	return 0;
} 
