#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 220
using namespace std;
struct node {
	double x[maxn][maxn];
};
node a;
int  b[maxn];
node muilt(node a,node b,int n){
	node c;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c.x[i][j]=0;
			for(int k=0;k<n;k++){
				c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j]);
			} 
		}
	}
	return c;
}
node dp(int k,node a,int n){
	node ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans.x[i][j]=a.x[i][j];
		}
	}
	k=k-1;
	while(k!=0){
		if(k%2==1){
			ans=muilt(ans,a,n);
			k=k-1;
		}
		a=muilt(a,a,n);
		k=k/2;
	}
	return ans;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0){
		memset(a.x,0,sizeof(a.x));
		for(int i=0;i<n;i++){
			a.x[i][i]=1.0;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		int t;
		scanf("%d",&t);
		for(int i=0;i<t;i++){
			int x,y;double z;
			scanf("%d%d%lf",&x,&y,&z);
			a.x[x][y]+=z;a.x[x][x]-=z;
		}
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				printf("%lf ",a.x[i][j]);
//			}
//			printf("\n");
//		}
		node res=dp(m,a,n);
		double ans=0;
		for(int i=0;i<n;i++){
			ans+=b[i]*res.x[i][n-1];
		}
		printf("%.0lf\n",ans);
	}
	return 0;
}
