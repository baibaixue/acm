#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 200005
#define mod 10007
using namespace std;
string str;
int len;
int n_next[maxn];
int dp[maxn];
void getnext(){
	int k=-1;
	n_next[0]=-1;
	for(int i=-1;i<len;i++){
		while(k>-1&&str[k+1]!=str[i]){
			k=n_next[k];
		}
		if(str[k+1]==str[i]){
			k=k+1;
		}
		n_next[i]=k;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&len);
		cin>>str;
		getnext();
		dp[0]=0;
		int ans=0;
		for(int i=1;i<len;i++){
			dp[i]=(dp[n_next[i]]+1)%mod;
			ans+=dp[i];
			ans=ans%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
