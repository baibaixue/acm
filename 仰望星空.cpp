#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long int n,a,b;
	while(scanf("%lld%lld%lld",&n,&a,&b)!=EOF){
		long long int ans=(b-a)*(n-2)+1;
		printf("%lld\n",ans);
	}
	return 0;
}
