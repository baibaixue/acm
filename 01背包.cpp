//01���� 
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define maxn 10000
using namespace std;
int val[maxn];//��ֵ 
int wei[maxn];//����
int dp[maxn];
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d%d",&wei[i].&val[i]);
		}
		for(int i=0;i<n,i++){
			for(int j=m;j>=wei[i];j--){
				dp[j]=max(dp[j],dp[j-wei[i]]+val[i]);
			}
		}
	}
	printf("%d\n",dp[m]);
} 
