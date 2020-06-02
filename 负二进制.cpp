#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 32
using namespace std;
int len;
void T2(long long n){
	int num[maxn];
	int r;
	len=0;
	long long a=n;
	while(a!=0){
		r=a%2;
		a=a/2;
		num[len++]=r;
	}
	for(int i=len-1;i>=0;i--){
		printf("%d",num[i]);
	}
}
void T_2(long long n){
	int num[maxn];
	int r;
	len=0;
	long long a=n;
	num[0]=0;
	while(a!=0){
		num[len]=a%2;
		a=a/2;
		if(len%2==1&&num[len]%2==1){
			a++;
		}
		len++;
	}
//	for(int i=len-1;i>0;i--){
//		if((len-1-i)%2!=0){
//			if(num[i]!=0){
//				num[i+1]=num[i+1]+1;
//			}
//		}
//	}
//	for(int i=len-1;i>0;i--){
//		if(num[i]==2){
//			num[i+1]=num[i+1]+1;
//			num[i]=0;
//		}
//	}
//	if(num[len]!=0){
//		printf("%d",num[len]);
//	}
	for(int i=len-1;i>=0;i--){
		printf("%d",num[i]);
	}
}
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		long long n;
		int k;
		scanf("%lld%d",&n,&k);
		if(k==2){
			T2(n);
		}else{
			T_2(n);
		}
		printf("\n");
	}
	return 0;
} 
