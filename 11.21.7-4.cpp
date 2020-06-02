#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

int main(){
//	memset(is_prime,0,sizeof(is_prime));
//	for(long long int i=1;i<maxn;i++){
//		if(is_prime[i]==0){
//			for(long long int j=2*i;j<maxn;j+=i){
//				is_prime[j]=1;
//			}
//		}
//	}
	int n;
	scanf("%d",&n);
	while(n--){
		long long int x;
		scanf("%lld",&x);
		int k=1;
		if(x==1){
			printf("No\n");
		}
		else{
			for(int i=2;i<=sqrt(x);i++){
				if(x%i==0){
					k=0;
				}
			}
			if(k==0){
				printf("No\n");
			}else{
				printf("Yes\n");
			}
		}
	}
	return 0;
}
