#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 100010
using namespace std;
int dp[maxn];
int a[maxn];
int b[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		int m;
		scanf("%d",&m);
		for(int i=1;i<=n;i++){
			for(int j=b[i];j<=m;j++){
				dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
			}
		}
		printf("%d\n",dp[m]);
	}
	return 0;
}
