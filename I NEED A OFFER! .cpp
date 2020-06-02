#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10010
using namespace std;
double dp[maxn];
double min(double x,double y)
{
	return x>y?y:x;
}

int main(){
	int  n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&(n!=0||m!=0)){
		int a;
		double b;
		//memset(dp,1.0,sizeof(dp));
		for(int i=0;i<maxn;i++){
			dp[i]=1.0;
		}
		for(int i=0;i<m;i++){
			scanf("%d%lf",&a,&b);
			for(int j=n;j>=a;j--){
				dp[j]=min(dp[j],dp[j-a]*(1.0-b));
				//printf("dp[%d]=%.3f\n",j,dp[j]);
			}
		}
		printf("%.1lf%%\n",(1-dp[n])*100);
	}
	return 0;
} 
