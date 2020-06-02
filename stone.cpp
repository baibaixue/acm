#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 10005 
using namespace std;
long long A[maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(A,0,sizeof(A));
		int n;
		scanf("%d",&n);
		long long Max=0;
		long long sum=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&A[i]);
			sum+=A[i];
			if(A[i]>Max){
				Max=A[i];
			}
		}
		printf("%lld\n",sum-Max);
	}
	return 0;
}
