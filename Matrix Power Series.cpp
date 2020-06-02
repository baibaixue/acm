#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 65
using namespace std;
struct node{
	int x[maxn][maxn];
};
node base;
int mod; 
node muilt(node a,node b,int n){
	node c;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c.x[i][j]=0;
			for(int k=0;k<n;k++){
				c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j])%mod;
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
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				printf("%d ",ans.x[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				printf("%d ",a.x[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
	}
	return ans;
}
int main(){
	int n,k;
	while(scanf("%d%d%d",&n,&k,&mod)!=EOF){
		memset(base.x,0,sizeof(base.x));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&base.x[i][j]);
			}
		}
		for(int i=n;i<2*n;i++){
			base.x[i-n][i]=1;
			base.x[i][i]=1;
		}
//		printf("|A E|\n|0 E|\n");
//		for(int i=0;i<2*n;i++){
//			for(int j=0;j<2*n;j++){
//				printf("%d ",base.x[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
		node ans=dp(k+1,base,2*n);
//		printf("|A^K ans|\n|0 E|\n"); 
//		for(int i=0;i<2*n;i++){
//			for(int j=0;j<2*n;j++){
//				printf("%d ",ans.x[i][j]);
//			}
//			printf("\n");
//		}
		for(int i=0;i<n;i++){
			for(int j=n;j<2*n;j++){
				if(j-n==i){
					ans.x[i][j]=ans.x[i][j]-1;
					if(ans.x[i][j]<0){
						ans.x[i][j]+=mod;
					}
				}
				printf("%d",ans.x[i][j]);
				if(j!=2*n-1){
					printf(" ");
				}
			}
			printf("\n");
		} 
	}
	return 0;
}
