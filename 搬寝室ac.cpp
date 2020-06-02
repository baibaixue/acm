#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2058;
long long last[maxn],dp[2][maxn],a[maxn],b[maxn];
int main(){
	int n,k,j;
	while(scanf("%d%d",&n,&k)==2){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			b[i]=(a[i]-a[i-1])*(a[i]-a[i-1]);//差值 
		}
		memset(last,0,sizeof(last));
		for(int i=1;i<=k;i++){//k次搬运即在b[i]中取k次 
			for(int j=2*i-1;j<n;j++){//还剩下的物品
				dp[1][j]=last[j-1]+b[j];//1为取下一个数值 
				if(j==2*i-1){// 初始两种情况相同 
					dp[0][j]=dp[1][j];
				}
				else{//找出拿与不拿两种情况的最小值 放入1 
					if(dp[0][j-1]<dp[1][j-1]){
						dp[0][j]=dp[0][j-1];
					}
					else{
						dp[0][j]=dp[1][j-1];
					}
				}
			}
			for(int j=2*i-1;j<n;j++){
				last[j]=dp[0][j];//将该轮循环产生的最小值存入last 
			}
		}
		long long max=dp[1][k*2-1];//在剩下k*2-1的情况里面找最大值 
		for(int i=k*2;i<n;i++){//即拿完k次后剩余的物品只有可能在2*k-1 
			if(dp[1][i]<max){//和n之间（之前未拿的物品直接跳过） 
				max=dp[1][i];//最大值为拿完k*2件物品的最小值 
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}
