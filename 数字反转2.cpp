#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	long long n;
	scanf("%lld",&n);
	int fu=0;
	if(n<0){
		fu=1;
		n=-n;
	}
	long long ans=0;
	while(n!=0){
		ans=ans*10+n%10;
		n=n/10;
	}
	while(ans%10==0){
		ans=ans/10;
	}
	if(fu==0){
		printf("%lld\n",ans);
	}else{
		printf("-%lld\n",ans);
	}
	return 0;
} 
