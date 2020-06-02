#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int is_prime(long long n){
	int i=2;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int num[40];
int ans[40];
int main(){
	int cnt=0;
	int len=0;
	int n;
	scanf("%d",&n);
	int N=sqrt(n);
	if(is_prime(n)==1){
		printf("1\n%d\n",n);
	}
	else{
		int ok=0;
		for(int i=N;i>=2&&ok==0;i--){
			cnt=0;
			if(n%i==0){
				num[cnt++]=i;
				int x=n/i;
				for(int j=i-1;j>=2;j--){
					if(x%j==0){
						num[cnt++]=j;
						x=x/j;
						if(j==2){
							ok=1;
						}
					}else{
						num[cnt]=0;
						break;
					}
				}
				if(cnt>=len){
					for(int i=0;i<cnt;i++){
						ans[i]=num[i];
					}
					len=cnt;
				}
			}
		}
		printf("%d\n",len);
		for(int i=len-1;i>=0;i--){
			printf("%d",ans[i]);
			if(i!=0){
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
} 
