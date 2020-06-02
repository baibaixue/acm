#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 120
using namespace std;
int p[2200];
int h[2200];
int dp[maxn];
int main(){
	int C;
	scanf("%d",&C);
	while(C--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof(dp));
		memset(p,0,sizeof(p));
		memset(h,0,sizeof(h));
		int a=1;
		for(int i=1;i<=m;i++){
			int P,H;
			scanf("%d%d",&P,&H);
			int c;
			scanf("%d",&c);
			for(int j=1;j<=c;j++){
				p[a]=P;
				h[a]=H; 
				a++;
			}
		}
		for(int i=1;i<=a;i++){
			for(int j=n;j>=p[i];j--){
				dp[j]=max(dp[j],dp[j-p[i]]+h[i]);
				printf("dp[%d]=%d\n",j,dp[j]);
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
 
