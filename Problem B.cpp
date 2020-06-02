#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
long long a[55];
long long b[55];
int main(){
	a[0]=0;a[1]=1;a[2]=1;a[3]=5;a[4]=9;
	b[0]=0;b[1]=1;b[2]=0;b[3]=4;b[4]=4;
	for(int i=3;i<41;i++){
		b[i]=(a[i-2]-b[i-5])*4;
		a[i]=b[i]+a[i-1]-b[i-4];
	}
	long long n;
	while(scanf("%lld",&n)!=EOF){
		printf("%lld\n",a[n]+b[n-4]);
	}
}
