#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath> 
#define maxn 200005
#define inf 0x3f3f3f3f
using namespace std;
struct node{
	long long ai;
	long long bi;
	double ave;
}num[maxn];
bool cmp(node a,node b){
	return a.ave>b.ave;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&num[i].ai);
			scanf("%lld",&num[i].bi);
			num[i].ave=num[i].ai-num[i].bi;
		}
		sort(num,num+n,cmp);
		long long A=0;
		long long B=0;
		int ans=0;
		for(int k=0;k<n;k++){
			A=A+num[k].ai;
			B=max(B,num[k].bi);
			//printf("A=%d B=%d k=%d\n",A,B,k);
			if(A-B>=0){
				ans=max(ans,k+1);
			}
		}
		printf("%d\n",ans);
	}
}
