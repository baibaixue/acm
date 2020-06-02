#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#define maxn 110
using namespace std;
int visit[maxn][maxn][maxn];
int step[maxn][maxn][maxn];
struct node{
	int x;
	int y;
	int z;
};
int bfs(int a,int b,int c){
	queue<node> Q;
	node now;
	now.x=a;
	now.y=0;
	now.z=0;
	Q.push(now);
	visit[a][0][0]=1;
	step[a][0][0]=0;
	while(!Q.empty()){
		now=Q.front();
		int k=0;
		if(now.x==a/2){
			k++;
		}if(now.y==a/2){
			k++;
		}if(now.z==a/2){
			k++;
		}
		if(k==2){
			return step[now.x][now.y][now.z];
		}
		Q.pop();
		node next;
		if(now.x!=0){
			if(now.y<b){
				if(now.x+now.y>b){
					next.x=now.x+now.y-b;
					next.y=b;
					next.z=now.z;
				}else{
					next.x=0;
					next.y=now.x+now.y;
					next.z=now.z;
				}
				if(visit[next.x][next.y][next.z]==0){
					Q.push(next);
					step[next.x][next.y][next.z]=step[now.x][now.y][now.z]+1;
					visit[next.x][next.y][next.z]=1;
				}
			}
			if(now.z<c){
				if(now.x+now.z>c){
					next.x=now.x+now.z-c;
					next.z=c;
					next.y=now.y;
				}else{
					next.x=0;
					next.z=now.x+now.z;
					next.y=now.y;
				}
				if(visit[next.x][next.y][next.z]==0){
					Q.push(next);
					step[next.x][next.y][next.z]=step[now.x][now.y][now.z]+1;
					visit[next.x][next.y][next.z]=1;
				}
			}
		}
		if(now.y!=0){
			if(now.x+now.y>a){
					next.x=a;
					next.z=now.z;
					next.y=now.y+now.z-a;
				}else{
					next.x=now.x+now.y;
					next.z=now.z;
					next.y=0;
				}
				if(visit[next.x][next.y][next.z]==0){
					Q.push(next);
					step[next.x][next.y][next.z]=step[now.x][now.y][now.z]+1;
					visit[next.x][next.y][next.z]=1;
				}
			if(now.z+now.y>c){
					next.x=now.x;
					next.z=c;
					next.y=now.y+now.z-c;
				}else{
					next.x=now.x;
					next.z=now.y+now.z;
					next.y=0;
				}
				if(visit[next.x][next.y][next.z]==0){
					Q.push(next);
					step[next.x][next.y][next.z]=step[now.x][now.y][now.z]+1;
					visit[next.x][next.y][next.z]=1;
				}
			}
		if(now.z!=0){
			if(now.x+now.z>a){
					next.z=now.z+now.x-a;
					next.x=a;
					next.y=now.y;
				}else{
					next.x=now.x+now.z;
					next.z=0;
					next.y=now.y;
				}
				if(visit[next.x][next.y][next.z]==0){
					Q.push(next);
					step[next.x][next.y][next.z]=step[now.x][now.y][now.z]+1;
					visit[next.x][next.y][next.z]=1;
				}
			if(now.z+now.y>b){
					next.z=now.y+now.z-b;
					next.y=b;
					next.x=now.x;
				}else{
					next.y=now.y+now.z;
					next.z=0;
					next.x=now.x;
				if(visit[next.x][next.y][next.z]==0){
					Q.push(next);
					step[next.x][next.y][next.z]=step[now.x][now.y][now.z]+1;
					visit[next.x][next.y][next.z]=1;
				}
			}
		}
		 
	}
	return -1;
}
int main(){
	int s,n,m;
	while(scanf("%d%d%d",&s,&n,&m)!=EOF&&s!=0&&n!=0&&m!=0){
		int t;
		if(n<m){
			t=n;n=m;m=t;
		}
		if(n==m){
			printf("1\n");
		}else{
			if(s%2==1){
				printf("NO\n");
			}else{
				memset(visit,0,sizeof(visit));
				int ans=bfs(s,n,m);
				if(ans==-1){
					printf("NO\n");
				}else{
					printf("%d\n",ans);
				}
			}
		}
	}
	return 0;
} 
