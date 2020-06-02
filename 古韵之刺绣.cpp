#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 110
using namespace std;
struct node{
	int id;
	int c,v;
}z[3];
int C[maxn];
int V[maxn];
int dp[8005];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<3;i++){
			scanf("%d%d%d",&z[i].id,&z[i].c,&z[i].v); 
		}
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			V[i]=a;
			for(int j=0;j<3;j++){
				if(b==z[j].id){
					C[i]=a*z[j].c;
					V[i]=a*z[j].v+a;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=m;j>V[i];j--){
				dp[j]=max(dp[j],dp[j-V[i]]+C[i]);
			}
		}
		printf("%d\n",dp[m]);
	}
	return 0;
}
