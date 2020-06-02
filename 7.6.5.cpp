#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#define inf 0f3x3x3x3x
#define maxn 10005
using namespace std; 
struct node{
	long long n;
	int id;
}num[maxn];
int N,M; 
int find(long long a){
	int l=1,r=N;
	int m;
	while(l<=r){
		m=(l+r)/2;
		if(num[m].n!=a){
			if(a>num[m].n){
				l=m+1;
			}else{
				r=m;
			}
		}else{
			return num[m].id;
		}
	}
	return -1;
}
bool cmp(node a,node b){
	return a.n<b.n;
}
int t[maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		for(int i=0;i<=N;i++){
			num[i].n=0;
			num[i].id=0;
		}
		memset(t,0,sizeof(t));
		for(int i=1;i<=N;i++){
			long long p;
			scanf("%lld",&num[i].n);
			num[i].id=i;
		}
		sort(num+1,num+N+1,cmp);
		for(int i=1;i<=M;i++){
			long long ti;
			scanf("%lld",&ti);
			t[i]=find(ti);
		}
		int ans=1;
		for(int i=1;i<=M-1;i++){
			if(t[i]>=t[i+1]){
				ans++;
			}
			if(t[i]==-1){
				ans=-1;
				break;
			}
		} 
		if(t[M]==-1){
			ans=-1;
		}
		printf("%d\n",ans);
	}
}
