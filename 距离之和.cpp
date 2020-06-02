#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1005
using namespace std;
long long N[maxn];
int cmp(long long a,long long b){
	return a<b;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		N[0]=0;
		long long sum=0;
		long long p;
		for(int i=1;i<=n;i++){
			scanf("%lld",&N[i]);
		}
		sort(N+1,N+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				p=N[i]-N[j];
				p=-p;
				sum+=p;
			}
		}
		printf("%lld\n",sum*2);
	}
	return 0;
} 
