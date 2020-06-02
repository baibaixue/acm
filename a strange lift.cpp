#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 220
using namespace std;
int n;
	int buttom[maxn];
	int visit[maxn];
	int steps[maxn];


int bfs(int x,int y){
	queue<int> Q;
	Q.push(x);
	visit[x]=1;
	while(!Q.empty()){
		int fir=Q.front();
		Q.pop();
		if(fir==y){
			return steps[fir];
		}else{
			int next;
			if(fir+buttom[fir]<=n){
				next=buttom[fir]+fir;
				if(visit[next]==0){
					Q.push(next);
					visit[next]=1;
					steps[next]=steps[fir]+1;
				}
			}if(fir-buttom[fir]>=1){
				next=fir-buttom[fir];
				if(visit[next]==0){
					Q.push(next);
					visit[next]=1;
					steps[next]=steps[fir]+1;
				}
			}
		}
	}
	return -1;
}
int main(){
	int a,b;
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d%d",&a,&b);
		for(int i=1;i<=n;i++){
			scanf("%d",&buttom[i]);
		}
		memset(visit,0,sizeof(visit)); 
		memset(steps,0,sizeof(steps));
		int ans=bfs(a,b);
		if(ans==-1){
			printf("-1\n");
		}else{
			printf("%d\n",steps[b]);
		}
	}
	return 0;
}
