#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 0x3f3f3f3f
using namespace std;
int is_prime(long long n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long n;
		scanf("%lld",&n);
		if(is_prime(n)){
			printf("1\n");
		}else{
			printf("0\n");
		}
	}
}
