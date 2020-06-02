#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue> 
#define maxn 100005
using namespace std;
//int num[maxn][13];
int dp[maxn][13];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int L,T;
		//memset(num,0,sizeof(num));
		memset(dp,0,sizeof(dp));
		int max_T=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&L,&T);
			//num[T][L]++;
			dp[T][L+1]++;
			if(T>max_T){
				max_T=T;
			}
		}
		//int l=4,r=6;
		/*for(int i=1;i<=max_T;i++)*/for(int i=max_T-1;i>0;i--){
			/*for(int x=max(l,0);x<=min(r,10);x++)*/for(int j=1;j<=11;j++){
				/*dp[i][x]=max(dp[i-1][x-1]+num[i][x],dp[i-1][x]+num[i][x]);
				dp[i][x]=max(dp[i-1][x+1]+num[i][x],dp[i][x]);*/
				int a=max(dp[i+1][j],dp[i+1][j-1]);
				a=max(dp[i+1][j+1],a); 
				dp[i][j]+=a;		
			}
			//l--;r++;

			}
			int m=max(dp[1][5],dp[1][7]);
			m=max(dp[1][6],m);
			printf("%d\n",m);
//		int max=dp[max_T][0];
//		for(int i=0;i<11;i++){
//			if(max<dp[max_T][i]){
//				max=dp[max_T][i];
//			}
//		}
//		printf("%d\n",max);
	}
	return 0;
}
