#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1010
using namespace std;
long long int chess[maxn];
long long int sum[maxn];
int cmp(long long int a,long long int b){
	return a>b;
}
long long int my_max(int a,int b){
	long long int max_chess;
	max_chess=0;
	for(int i=a+1;i<b;i++){
		if(chess[a]<chess[i]&&sum[i]>max_chess){
			max_chess=sum[i];
		}
	}
	return max_chess;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		memset(chess,0,maxn);
		memset(sum,0,maxn);
		for(int i=0;i<n;i++){
			scanf("%lld",&chess[i]);
		}
		for(int i=n-1;i>=0;i--){
			sum[i]=chess[i]+my_max(i,n);
		}
		//sort(sum,sum+n,cmp);
		for(int i=1;i<n;i++){
			if(sum[i]>sum[0]){
				sum[0]=sum[i];
			}
		}
		printf("%lld\n",sum[0]);
	}
	return 0;
}
