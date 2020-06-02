#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define maxn 10005
using namespace std;
vector<int> v[maxn];
int map[maxn][maxn];                                                                                        
int in[maxn];
int ans[maxn];
void bfs(int st){
	if(v[st].empty()){
		return ;
	}
	for(int i=0;i<v[st].size();i++){
		int e=v[st][i];
		if(map[e][st]!=0){
			ans[e]=max(ans[e],ans[st]+map[e][st]);
		}
		bfs(e);
	}
	return ;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<=n;i++){
			v[i].clear();
			in[i]=0;
			ans[i]=0;
		}
		memset(map,0,sizeof(map));
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			map[a][b]=c;
			in[a]++;
			v[b].push_back(a); 
		}
		int st;
		for(int i=1;i<=n;i++){
			if(in[i]==0){
				st=i;
				break;
			}
		}
		bfs(st);
		for(int i=1;i<n;i++){
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[n]);
	}
	return 0;
}
