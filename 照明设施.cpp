#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#define maxn 1005
using namespace std;
struct node{
	int x,y;
	int r;
}c[maxn];
bool dis[maxn][maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(dis,false,sizeof(dis));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].r);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				double len=(1.0*c[i].x-c[j].x)*(1.0*c[i].x-c[j].x)+(1.0*c[i].y-c[j].y)*(1.0*c[i].y-c[j].y);
				double R=c[i].r*1.0+c[j].r;
				if(R*R<len){
					dis[i][j]=false;
				}else{
					dis[i][j]=true;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dis[i][j]==true){
					printf("%d %d\n",i,j);
				}
			}
		}
	}
	return 0;
}
