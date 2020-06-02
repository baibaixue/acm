#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10010
using namespace std;
long long int dp[maxn];
int main(){
	int t;
	scanf("%d",&t);
	int e,f;
	int n;
	int w,p;
	while(t--){
		scanf("%d%d",&e,&f);
		scanf("%d",&n);
		f=f-e;
		memset(dp,0x3f3f3f3f,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&p,&w);
			for(int j=w;j<=f;j++){
				dp[j]=min(dp[j],dp[j-w]+p);
					printf("dp[%d]=%d\n",j,dp[j]);
				}
			}
		if(dp[f]!=dp[maxn-1]){
			printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[f]);
		}else{
			printf("This is impossible.\n");
		}
	}
	return 0;
}
