#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath> 
#define maxn 100100
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;
long long num[maxn];
int a[maxn];
long long modd[maxn];
int main(){
	int T;
	scanf("%d",&T);
	memset(modd,0,sizeof(modd));
	modd[0]=1;
	modd[1]=1;
	for(int i=2;i<=100000;i++){
		modd[i]=(modd[i-1]*i)%mod;
	}
	while(T--){
		int n;
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			num[a[i]]++;
		}
		long long ans=1;
		for(int i=0;i<=n;i++){
			ans=(ans*modd[num[i]])%mod;
		}
		printf("%lld\n",ans);
	}
}
