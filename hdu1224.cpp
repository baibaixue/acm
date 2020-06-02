#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#define maxn 120
using namespace std;
int link[maxn][maxn];
int city[maxn];
int ans[maxn];
int pre[maxn];
int ans2[maxn];
int visit[maxn];
//struct node{
//	int c;
//	//int trip[maxn];
//};
void spfa(int n){
	queue<int>Q;
	int last,next;
	last=1;
	//memset(last.trip,0,sizeof(last.trip));
	//last.trip[1]=1;
	Q.push(last);
	visit[last]=1;
	while(!Q.empty()){
		last=Q.front();
		//visit[last]=0;
		Q.pop();
		for(int i=last+1;i<=n+1;i++){
			if(link[last][i]==1&&visit[i]!=1){
				if(ans[i]<=ans[last]+city[i]){
					next=i;
					ans[i]=ans[last]+city[i];
					pre[i]=last;
//					for(int j=0;j<=n+1;j++){
//						next.trip[j]=last.trip[j];
//					}
//					next.trip[last.c]=1;
//					next.trip[i]=1;
					Q.push(next);
					//visit[next]=1;
				}
			}
		}
	}
	return ;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		int n,m;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&city[i]);
		}
		city[n+1]=0;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			link[a][b]=1;
		}
		memset(ans,0,sizeof(ans));
		memset(ans2,0,sizeof(ans2));
		memset(visit,0,sizeof(visit));
		spfa(n);
		printf("CASE %d#\npoints : %d\ncircuit : 1",T,ans[n+1]);
		int a=n+1;
		while(a!=1){
			ans2[a]=1;
			a=pre[a];
		}
		for(int i=2;i<=n;i++){
			if(ans2[i]==1){
				printf("->%d",i);
			}
		}
		printf("->1");
		if(T!=t){
			printf("\n");
		}
	}
	return 0;
}
