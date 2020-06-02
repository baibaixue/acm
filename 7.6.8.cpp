#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define inf 1e9+5
#define maxn 100005
using namespace std;
long long W[maxn];
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n==1){
			int p;
			long long w;
			scanf("%d",&p);
			for(int j=0;j<p;j++){
				scanf("%lld",&w);
			}
			printf("0\n"); 
		}else{
			int m_p=0;
			int is_ok=1;
			long long sum=0;
			for(int i=0;i<n;i++){
				int p;
				scanf("%d",&p);
				if(p==0){
					is_ok=0;
				}
				long long minn=inf;
				int t=0;
				for(int i=m_p;i<m_p+p;i++){
					scanf("%lld",&W[i]);
					if(W[i]<=minn){
						minn=W[i];
						t=i;
					}
				}
				m_p+=p;
				sum+=minn;
				W[t]=inf;
			}
			if(m_p<(n-1)*2){
				is_ok=0;
			}
			if(is_ok==0){
				printf("-1\n");
			}else{
				sort(W,W+m_p,cmp);
				for(int i=0;i<(n-1)*2-n;i++){
					sum+=W[i];
				}
				printf("%lld\n",sum);
			}
		}
		
	}
}
