#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 5843
using namespace std;
long long dp[2][maxn];
//long long last[maxn];
int main(){
	int n;
		memset(dp,0,sizeof(dp));
//		for(int i=11;i<=n;i++){
//			last[i]=2e9;
//		}
		for(int i=1;i<=10;i++){
			dp[0][i]=i;
			dp[1][i]=i;
			//last[i]=i;
		}
		for(int i=11;i<=maxn;i++){
			//dp[1][i-1]=last[i-1];
			for(int j=1;j<=i;j++){
				if(dp[1][j]*2>dp[1][i-1]){
					dp[0][j]=dp[1][j]*2;
				}else if(dp[1][j]*3>dp[1][i-1]){
					dp[0][j]=dp[1][j]*3;
				}else if(dp[1][j]*5>dp[1][i-1]){
					dp[0][j]=dp[1][j]*5;
				}else if(dp[1][j]*7>dp[1][i-1]){
					dp[0][j]=dp[1][j]*7;
				}else{
					dp[0][j]=2e9;
				}
			}
			int min=dp[0][1];
			for(int j=1;j<=i;j++){
				if(min>dp[0][j]){
					min=dp[0][j];
				}
			}
			dp[1][i]=min;
		}
		while(scanf("%d",&n)!=EOF&&n){
			if(n%10==1&&n%100!=11){
				printf("The %dst humble number is %lld.",n,dp[1][n]);
			}else if(n%10==2&&n%100!=12){
				printf("The %dnd humble number is %lld.",n,dp[1][n]);
			}else if(n%10==3&&n%100!=13){
				printf("The %drd humble number is %lld.",n,dp[1][n]);
			}else{
				printf("The %dth humble number is %lld.",n,dp[1][n]);
			}
			printf("\n");
	}
	return 0;
}
