#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define maxn 
#define inf 0x3f3f3f3f
using namespace std;
int g(int n){
	long long a=1;
	for(int i=1;i<=n;i++){
		a*=i;
	}
	return a;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",g(x-1)+1);
	}
}
