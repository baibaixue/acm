#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 100005
#define inf 0x3f3f3f3f 
using namespace std;
int dp[maxn];
int V[maxn];
int p[maxn];
int num[maxn];
int main(){
	int n,v;
	while(scanf("%d%d",&n,&v)!=EOF){
		int m,w,s;
		memset(dp,0,sizeof(dp));
		memset(V,0,sizeof(V));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&m,&w,&s);
//			while(m){
				p[i]=s;
				V[i]=w;
				num[i]=m;
//				num++;
//				m=m/2;
//			}
		}
		for(int i=1;i<=n;i++){
			for(int j=v;j>=0;j--){
				for(int k=0;k<=num[i];k++){
					if(j<k*V[i]){
						break;
					}
					dp[j]=max(dp[j],dp[j-k*V[i]]+k*p[i]);
				}
				
			}
		}
		printf("%d\n",dp[v]);
	}
	return 0;
}
