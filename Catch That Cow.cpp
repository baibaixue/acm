#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string.h>
#define maxn 100010
using namespace std;
int minite[maxn];
int visit[maxn];
int bfs(int a,int b){
	queue<int> Q;
	Q.push(a);
	visit[a]=1;
	minite[a]=0;
	while(!Q.empty()){
		int now;
		now=Q.front();
		if(now==b){
			return minite[now];
		}
		Q.pop();
		int next;
		if(now*2>0&&now*2<=100000){
			next=now*2;
			if(visit[next]==0){
				Q.push(next);
				visit[next]=1;
				minite[next]=minite[now]+1;
			}
		}
		if(now+1<=100000){
			next=now+1;
			if(visit[next]==0){
				Q.push(next);
				visit[next]=1;
				minite[next]=minite[now]+1;
			}
		}
		if(now-1>=0){
			next=now-1;
			if(visit[next]==0){
				Q.push(next);
				visit[next]=1;
				minite[next]=minite[now]+1;
			}
		}
	}
	return -1;
}
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(visit,0,sizeof(visit));
		int move=bfs(n,k);
		printf("%d\n",move);
	}
	return 0;
} 
