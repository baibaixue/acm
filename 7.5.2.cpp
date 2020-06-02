#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define inf 0x3f3f3f
#define maxn 1000005
using namespace std;
struct t{
	int Ti;
	int Ai;
	double ave;
};
t x[maxn];
bool cmp(t a,t b){
	if(a.ave==b.ave){
		return a.Ti<b.Ti;
	}
	return a.ave>b.ave;
}
int main(){
	int n;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x[i].Ti);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&x[i].Ai);
			x[i].ave=x[i].Ai*1.0/x[i].Ti;
		} 
		sort(x,x+n,cmp);
		long long m=0;
		long long ans=0;
		for(int i=0;i<n;i++){
			m+=x[i].Ti;
			ans+=x[i].Ai*m; 
		}
		printf("%lld\n",ans);
	}
} 
