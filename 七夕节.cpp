#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 500050
using namespace std;
int num[maxn];
int main(){
	memset(num,0,maxn);
	for(int i=1;i<=500000;i++){
		for(int j=i*2;j<=500000;j+=i){
			num[j]+=i;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",num[n]);
	}
	return 0;
} 
