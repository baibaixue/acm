#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n;
		scanf("%lld",&n);
		int ans=0;
		while(n>1){
			if(n%10!=0){
				ans+=10-n%10;
				n=n+10-n%10;
			}
			
			n=n/10;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
