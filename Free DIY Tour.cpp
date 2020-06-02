#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 120
using namespace std;
int city[maxn];
int link[maxn][maxn];
int dp[maxn];
int pre[maxn];
int road[maxn];
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		city[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&city[i]);
		}
		city[n+1]=0;
		int m;
		scanf("%d",&m);
		memset(link,0,sizeof(link));
		memset(road,0,sizeof(road));
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			link[a][b]=1;
		}
		for(int i=2;i<=n+1;i++){
			dp[i]=city[i];
			int x=0;
			for(int j=n;j>=1;j--){
				if(link[j][i]==1&&dp[j]>=x){
					x=dp[j];
					pre[i]=j;
				}
			}
			dp[i]+=x;
		}
		printf("CASE %d#\npoints : %d\ncircuit : 1",t,dp[n+1]);
		int a=n+1;
		while(a!=1){
			road[a]=1;
			a=pre[a];
		}
		for(int i=1;i<=n;i++){
			if(road[i]==1){
				printf("->%d",i);
			}
		}
		printf("->1\n");
		if(t!=T){
			printf("\n");
		}
	}
	return 0;
}
