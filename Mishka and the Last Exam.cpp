#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 400005
using namespace std;
long long A[maxn];
long long B[maxn]; 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n/2;i++){
			scanf("%I64d",&B[i]);
		}
		A[1]=0;
		A[n]=B[1];
		
		for(int i=2;i<=n/2;i++){
			A[i]=A[i-1];
			B[i]=B[i]-A[i-1];
			if(B[i]>A[n-i+2]){
				A[i]+=B[i]-A[n-i+2];
				A[n-i+1]=A[n-i+2];
			}else{
				A[n-i+1]=B[i];
			}
		}
		printf("%I64d",A[1]);
		for(int i=2;i<=n;i++){
			printf(" %I64d",A[i]);
		}
		printf("\n");
	}
	return 0;
} 
