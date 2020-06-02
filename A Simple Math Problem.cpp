#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 11
using namespace std;
int mod;
int base[maxn][1];
struct node{
	int x[maxn][maxn];
};
node a;
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
	}
	return ans;
}
int main(){
	long long k;
	while(scanf("%lld%d",&k,&mod)!=EOF){
		memset(a.x,0,sizeof(a.x));
		for(int i=0;i<10;i++){
			scanf("%d",&a.x[0][i]);
		}
		for(int i=1;i<10;i++){
			a.x[i][i-1]=1;
		}
		node res=dp(k-9,a,10);
//		for(int i=0;i<10;i++){
//			for(int j=0;j<10;j++){
//				printf("%d ",res.x[i][j]);
//			}
//			printf("\n");
//		}
		int ans=0;
		for(int i=0;i<10;i++){
			ans+=res.x[0][i]*(10-i-1);
			ans=ans%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
