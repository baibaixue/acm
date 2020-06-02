#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 500
#define inf 0x3f3f3f3f
using namespace std;
int edge[maxn][maxn];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		memset(edge,inf,sizeof(edge));
		int d;char c;
		for(int i=1;i<=(n+1)*(m+1);i++){
			edge[i][i]=0;
		}
		for(int i=0;i<=n;i++){
				for(int j=1;j<=m;j++){
					scanf("%d",&d);
					scanf("%*c%c",&c);
					if(d!=0){
						d=2520/d;
					}else{
						d=inf;
					}
					if(c=='*'){
						edge[i*(m+1)+j][i*(m+1)+j+1]=d;
						edge[i*(m+1)+j+1][i*(m+1)+j]=d;
					}
					if(c=='<'){
						edge[i*(m+1)+j+1][i*(m+1)+j]=d;
					}
					if(c=='>'){
						edge[i*(m+1)+j][i*(m+1)+j+1]=d;
					}
				}
				if(i!=n){
					for(int j=1;j<=m+1;j++){
						scanf("%d",&d);
						scanf("%*c%c",&c);
						if(d!=0){
							d=2520/d;
						}else{
							d=inf;
						}
						if(c=='*'){
							edge[i*(m+1)+j][(i+1)*(m+1)+j]=d;
							edge[(i+1)*(m+1)+j][i*(m+1)+j]=d;
						}if(c=='v'){
							edge[i*(m+1)+j][(i+1)*(m+1)+j]=d;
						}if(c=='^'){
							edge[(i+1)*(m+1)+j][i*(m+1)+j]=d;
						}
					}
				}
			}
		for(int k=1;k<=(n+1)*(m+1);k++){
			for(int i=1;i<=(n+1)*(m+1);i++){
				for(int j=1;j<=(n+1)*(m+1);j++){
					edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
				}
			}
		}
		if(edge[1][(n+1)*(m+1)]==inf){
			printf("Holiday\n");
		}else{
			printf("%d blips\n",edge[1][(n+1)*(m+1)]);
		}
	}
	return 0;
}  
