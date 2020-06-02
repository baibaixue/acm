#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int p;
	scanf("%d",&p);
	while(p--){
		long long int n,m;
		scanf("%lld%lld",&n,&m);
		if((m%n==0&&n!=1)||(n%2==0&&m%2==0)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
} 
