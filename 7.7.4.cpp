#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define maxn 
#define inf 0x3f3f3f3f
using namespace std;


long long g(int n){
	long long ans=1;
	for(int i=0;i<n;i++){
		ans=ans*2;
	}
	return ans;
}
long long f(long long n){
	long long ans=n;
	for(int i=2;;i++){
		long long x=g(i);
		long long a=n/x;
		if(a>0){
			if(n%x!=0){
				ans+=a;
			}
		}else{
			break;
		}
	}
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long n;
		scanf("%lld",&n);
		//printf("%lld\n",4*n-f(n));
		printf("%lld\n",f(n));
	}
} 
