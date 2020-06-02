#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int prime[10000]={2,3,5}; 
int len=3;
int bsearch(int k){
	int l=0,r=len;
	int m;
	while(l<=r){
		m=(l+r)/2;
		if(prime[m]==k){
			return 1;
		}
		if(prime[m]<k){
			l=m+1;
		}
		if(prime[m]>k){
			r=m-1;
		}
	}
	return 0;
}
int main(){
	int k;
	for(int i=6;i<10000;i++){
		k=1;
		for(int j=0;j<len;j++){
			if(i%prime[j]==0){
				k=0;
				break;
			}
		}
		if(k==1){
			prime[len]=i;
			len++;
		}
	}
//	for(int i=0;i<len;i++){
//		printf("%d ",prime[i]);
//	}
//	printf("\n");
	int n;
	while(scanf("%d",&n)!=EOF){
		int count=0;
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&k);
			if(bsearch(k)==1){
				count++;
			}
		}
		printf("%d\n",count);
	}
	return  0;
} 
