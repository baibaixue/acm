//完全背包
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define maxn 10000
#define inf 0x3f3f3f3f
using namespace std;
int val[maxn];//价值 
int wei[maxn];//重量
int dp[maxn]; 
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		//注意初始化（要求恰好装满背包，那么在初始化时除了f[0]为0其他f[1..V]均设为-∞。
		//这样就能够保证终于得到的dp[N]是一种恰好装满背包的最优解。
		//如果并没有要求必须把背包装满。而是仅仅希望价格尽量大，初始化时应该将f[0..V]所有设为0）
		for(int i=0;i<m;i++){
			dp[i]=-inf;
		}
		dp[0]=0;
		for(int i=0;i<n;i++){
			for(int j=wei[i];j<=m;j++){
				dp[j]=max(dp[j],dp[j-wei[i]]+val[i]);
			}
		}
		printf("%d\n",dp[m]);
	}
}
