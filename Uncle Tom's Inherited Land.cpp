#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 105
using namespace std;
int map[maxn][maxn];
struct node{
	int x,y;
};
int link[505];
vector<int> edge[505];
int visit[505];
int n,m,k;
int cnt;
node all_node[505];
void get_node(){
	node a;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]==0){
				a.x=i;a.y=j;
				all_node[cnt]=a;
				cnt++;
			}
		}
	}
}
bool is_next(node a,node b){
	if(abs(a.x-b.x)+abs(a.y-b.y)==1){
		return true;
	}else{
		return false;
	}
}
void build_edge(){
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++){
			if(is_next(all_node[i],all_node[j])==true){
				edge[i].push_back(j); 
			}
		}
	}
}
int find(int x){
	for(int i=0;i<edge[x].size();i++){
		if(visit[edge[x][i]]==0&&(all_node[edge[x][i]].x+all_node[edge[x][i]].y)%2==1){
			visit[edge[x][i]]=1;
			if(link[edge[x][i]]==-1||find(link[edge[x][i]])){
				link[edge[x][i]]=x;
				return 1;
			}
		}
	}
	return 0;
}
int kmp(){
	int sum=0;
	for(int i=0;i<cnt;i++){
		memset(visit,0,sizeof(visit)); 
		if((all_node[i].x+all_node[i].y)%2==0){
			if(find(i)){
				sum++;
			}
		}	
	}
	return sum;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
		if(n==0||m==0){
			return 0;
		}
		scanf("%d",&k);
		memset(map,0,sizeof(map));
		cnt=0;
		for(int i=0;i<k;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			map[a][b]=1;
		}
		get_node();
		for(int i=0;i<cnt;i++){
			link[i]=-1;
		}
		for(int i=0;i<cnt;i++){
			edge[i].clear();
		}
		build_edge();
		int ans=kmp();
		printf("%d\n",ans);

		for(int i=0;i<cnt;i++){
			if(link[i]!=-1){
				printf("(%d,%d)--(%d,%d)\n",all_node[link[i]].x,all_node[link[i]].y,all_node[i].x,all_node[i].y);
			}
		}
	}
}

