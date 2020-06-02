#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
int num[22];
int cnt=0;
int n;
int is_prime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void add(int x,int l,int k){
	if(k==0&&is_prime(x)==1){
		cnt++;
		return ;
	}else if(k==0&&is_prime(x)==0){
		return;
	}else if(k!=0){
		for(int i=l;i<=n-k;i++){
			x+=num[i];
			add(x,i+1,k-1);
			x-=num[i];
		}
	}
}
int main(){
	scanf("%d",&n);
	int k;
	scanf("%d",&k);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	add(0,0,k);
	printf("%d\n",cnt);
	return 0;
}
