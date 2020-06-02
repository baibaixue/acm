#include<cstdio>
unsigned long long n[10005];
const int mod=1e8+7;
int main(){
	n[0]=1;
	n[1]=1;
	n[2]=2;
	for(int i=3;i<=10000;i++){
		n[i]=((n[i-2]+mod)*2-n[i-3]+n[i-1])%mod;
	}
	long long N;
	scanf("%lld",&N);
	printf("%lld\n",n[N]);
	return 0;
} 
