#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10005
using namespace std;
int N[maxn];
int cmp(int a,int b){
	return a<b;
}
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&N[i]);
		}
		sort(N+1,N+n+1,cmp);
		int now=N[n];
		for(int i=n-1;i>=1;i--){
			now=(now+N[i])/k;
		}
		printf("%d\n",now);
	}
	return 0;
}
