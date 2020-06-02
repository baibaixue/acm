#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 1005
using namespace std;
int cake[maxn];
int main(){
	int n,k;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&k);
		for(int i=0;i<n;i++){
			scanf("%d",&cake[i]);
		}
		int sum=0,count=0;
		for(int i=0;i<n;i++){
			sum+=cake[i];
			if(sum>=k){
				count++;
				sum=0;
			}
		}
		if(sum>0){
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
