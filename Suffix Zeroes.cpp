#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 100005
int num[maxn];
int zero(int n){
	int count=0;
	int a=5;
	while(n>=a){
		count+=n/a;
		a*=5;
	} 
	return count;
}
int search_zero(int k){
	int l=1,r=5e8;
	int m;
	while(l<=r){
		m=(l+r)/2;
		if(zero(m)==k){
			return m;
		}else if(zero(m)<k){
			l=m+1;
		}else{
			r=m-1;
		}
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n;
		scanf("%d",&n);
		int ans=search_zero(n);
		if(ans==-1){
			printf("Case %d : Impossible\n",i);
		}else{
			printf("Case %d : %d\n",i,ans);
		}
	}
	return 0;
}
