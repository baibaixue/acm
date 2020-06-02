#include<cstdio>
#include<iostream>
#include<algorithm>
#define mod 10000
using namespace std;
struct node{
	int x[2][2];
};
node base;
node muilt(node a,node b){
	node c;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			c.x[i][j]=0;
			for(int k=0;k<2;k++){
				c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j])%mod;
			} 
		}
	}
	return c;
}
node dp(int n,node a){
	node ans;
	ans.x[0][0]=1;ans.x[1][1]=0;
	ans.x[1][0]=1;ans.x[0][1]=1;
	n=n-1;
	while(n!=0){
		if(n%2==1){
			ans=muilt(ans,a);
			n=n-1;
		}
		a=muilt(a,a);
		n=n/2;
	}
	return ans;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=-1){
		base.x[0][0]=1;base.x[0][1]=1;
		base.x[1][0]=1;base.x[1][1]=0;
		if(n==0){
			printf("0\n");
		}else{
			node ans=dp(n,base);
			printf("%d\n",ans.x[0][1]);
		}
	}
	return 0;
}
