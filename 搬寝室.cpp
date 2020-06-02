#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1005
using namespace std;
int dp[2][maxn];
int num[maxn*2];
//int left[maxn];
//int right[maxn];
int chazhi[maxn];
int main(){
	int k,n;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=0;i<=n;i++){
			dp[1][i]=2147483647;
			dp[2][i]=2147483647
		}
		memset(num,0,sizeof(num)); 
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
		}
		sort(num+1,num+1+n);
		dp[0]=0;
		for(int i=2;i<=n;i+=2){
			for(int j=k*2;j>=2;j-=2){
				if(dp[2][j-2]!=2147483647){
					if(dp[2][j]>=dp[2][j-2]+(num[i]-num[i-1])*(num[i]-num[i-1])){
						dp[2][j]=dp[2][j-2]+(num[i]-num[i-1])*(num[i]-num[i-1]);
						//num[i]=0;
						//num[i-1]=0;
					}
				}
				printf("dp[%d]=%d\n",j,dp[j]);
			}
		}
		for(int i=1;i<=n;i+=2){
			for(int j=k*2;j>=2;j-=2){
				if(dp[j-2]!=2147483647){
					if(dp[j]>=dp[j-2]+(num[i]-num[i-1])*(num[i]-num[i-1])){
						dp[j]=dp[j-2]+(num[i]-num[i-1])*(num[i]-num[i-1]);
						//num[i]=0;
						//num[i-1]=0;
					}
				}
				printf("dp[%d]=%d\n",j,dp[j]);
			}
		}
		printf("%d\n",dp[k*2]); 
	} 
	return 0;
} 
