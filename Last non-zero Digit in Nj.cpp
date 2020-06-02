#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#define maxn 10005
using namespace std;
int zero[maxn];
int main(){
	memset(zero,0,sizeof(zero));
	for(int i=1;i<maxn;i++){
		int k=0;
		int a=i;
		while(a!=0&&a%5==0){
			a=a/5;
			k++;
		}
		zero[i]=k;
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		long long int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i;
			if(zero[i]!=0){
				ans=ans/(long long int)pow(10.0,(double)(zero[i]));
			}
			ans=ans%10000;
		}
		printf("%d\n",ans%10);
	}
	return 0;
} 
