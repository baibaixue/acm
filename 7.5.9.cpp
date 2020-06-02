#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn  200005
using namespace std;
long long a[maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,c;
		long long k;
		scanf("%d%lld%d",&n,&k,&c);
		int cnt=0;
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(a[i]>k){
				cnt++;
			}else{
				if(cnt>=c){
					ans+=(cnt-c+1);
				}
				cnt=0;
			}
		}
		if(cnt>=c){
			ans+=cnt-c+1;
		}
		printf("%d\n",ans);
	}

}
