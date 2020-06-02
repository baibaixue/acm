#include<cstdio> 
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 105
using namespace std;
int connect [maxn][maxn];
int friends[maxn];
int find(int x){
	int r=x;
	if(r==friends[r]){
		return r;
	}else{
		return find(friends[r]);
	}
}
void link(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		friends[b]=a;
	}
}
int main(){
	int n,m,k;
	memset(connect,0,sizeof(connect));
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		for(int i=0;i<maxn;i++){
			friends[i]=i;
		}
		for(int i=0;i<m;i++){
			int a,b,flag;
			scanf("%d%d%d",&a,&b,&flag);
			connect[a][b]=flag;
			connect[b][a]=flag;
			if(flag==1){
				link(a,b);
			}
		}
		int x,y;
		for(int i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			if(connect[x][y]==1){
				printf("No problem\n");
			}if(connect[x][y]==0){
//				int l=0;
//				for(int j=0;j<n;j++){
//					if(connect[x][j]==1&&connect[y][j]==1){
//						l=1;
//						break;
//					}
//				}
//				if(l==1){
//					printf("Noproblem\n");
//				}else{
					printf("OK\n");
				//}
			}if(connect[x][y]==-1){
				if(find(x)==find(y)){
					printf("OK but...\n");
				}
				else{
					printf("No way\n");
				}
			}
		}
	}
	return 0;
}
