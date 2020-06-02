#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 50
using namespace std;
struct node {
	long long x[maxn][maxn];
};
node muilt(node a,node b,int n){
	node c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c.x[i][j]=0;
			for(int k=1;k<=n;k++){
				c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j]);
			} 
		}
	}
	return c;
}
node dp(int k,node a,int n){
	node ans;
	memset(ans.x,0,sizeof(ans.x));
	for(int i=1;i<=n;i++){
		ans.x[i][i]=1;
	}
	while(k!=0){
		if(k%2==1){
			ans=muilt(ans,a,n);
			k=k-1;
		}
		a=muilt(a,a,n);
		k=k/2;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				printf("%d ",ans.x[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		node a;
		scanf("%d%d",&m,&n);
		getchar();
		memset(a.x,0,sizeof(a.x));
		int x1,y1,x2,y2,x3,y3,x4,y4;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("((%d,%d),(%d,%d),(%d,%d),(%d,%d))",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
				getchar();
				if(i==m&&j==n) continue;
				a.x[(i-1)*n+j][(x1-1)*n+y1]=1;
				a.x[(i-1)*n+j][(x2-1)*n+y2]=1;
				a.x[(i-1)*n+j][(x3-1)*n+y3]=1;
				a.x[(i-1)*n+j][(x4-1)*n+y4]=1;
			}
		}
//		for(int i=1;i<=n*m;i++){
//			for(int j=1;j<=n*m;j++){
//				printf("%d ",a.x[i][j]);
//			}
//			printf("\n");
//		}
		int q,p;
		node res;
		scanf("%d",&q);
		while(q--){
			scanf("%d",&p);
			res=dp(p,a,n*m);
			if(res.x[1][n*m]==0){
				printf("False\n");
			}else{
				int ok=0;
				for(int i=1;i<n*m;i++){
					if(res.x[1][i]){
						ok=1;
						break;
					}
				}
				if(ok==1){
					printf("Maybe\n");
				}else{
					printf("True\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
