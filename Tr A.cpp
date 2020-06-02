#include<cstdio>
#include<iostream>
#include<algorithm>
#define mod 9973
#define maxn 12
using namespace std;
struct node{
	int x[maxn][maxn];
};
node base;
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
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&base.x[i][j]);
			}
		}
		node ans=dp(k,base,n);
		int res=0;
		for(int i=0;i<n;i++){
			res=(res+ans.x[i][i])%mod;
		} 
		printf("%d\n",res);
	}
	return 0;
}
