#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#define maxn 205
using namespace std;
struct node{
	int ai;
	int bi;
}N[maxn];
int K[105];
int cmp(node a,node b){
	return a.ai>b.ai;
}
int ans;
int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		memset(K,0,sizeof(K));
		memset(N,0,sizeof(N));
		ans=0;
		for(int i=1;i<=k;i++){
			scanf("%d",&K[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d",&N[i].ai,&N[i].bi);
		}
		sort(N+1,N+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(m!=0){
				if(K[N[i].bi]!=0){
					ans+=N[i].ai;
					K[N[i].bi]--;
					m--;
				}
			}else{
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
