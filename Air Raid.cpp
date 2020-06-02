#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 505
using namespace std;
int road[maxn],used[maxn];
int link[maxn][maxn];
int n;
int find(int x){
	for(int i=1;i<=n;i++){
		if(link[x][i]!=0&&used[i]==0){
			used[i]=1;
			if(road[i]==0||find(road[i])){
				road[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int k;
	while(scanf("%d",&k)!=EOF&&k){
		while(k--){
			int m;
			scanf("%d%d",&n,&m);
			memset(road,0,sizeof(road));
			memset(used,0,sizeof(used));
			memset(link,0,sizeof(link));
			for(int i=0;i<m;i++){
				int a,b;
				scanf("%d%d",&a,&b);
				link[a][b]=1;
			}
			int sum=0;
			for(int i=1;i<=n;i++){
				memset(used,0,sizeof(used));
				if(find(i)){
					sum++;
				}
			}
			printf("%d\n",n-sum);
		}
	}
} 
