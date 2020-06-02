#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn1 5010
#define maxn2 125005
using namespace std;
int V[maxn1];
int dp[maxn2];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n>=0){
		memset(V,0,sizeof(V));
		memset(dp,0,sizeof(dp));
		int len=0;
		int k;int v;
		int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&v,&k);
			for(int j=0;j<k;j++){
				V[len++]=v;
				sum+=v;
			}
		}
		for(int i=0;i<len;i++){
			for(int j=sum/2;j>=V[i];j--){
				dp[j]=max(dp[j],dp[j-V[i]]+V[i]);
			}
		}
		printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
	}
	return 0;
}

