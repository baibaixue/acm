#include<cstdio>
#include<iostream>
#include<iostream>
#include<string.h>
#include<cmath>
#define maxn 32790
using namespace std;
//int num[maxn];
//int gongyueshu(int a,int b){
//	int x;
//	while(b!=0){
//			x=a%b;
//			a=b;
//			b=x;
//		}
//	return a;
//}
int a[40000];
void prime(){
	a[1]=1;
	for(int i=2;i<=sqrt(maxn*1.0);i++){
		if(a[i]!=1){
			for(int j=2*i;j<maxn;j+=i){
				a[j]=1;
			}
		}
	}
}
int main(){
//	memset(num,0,maxn);
//	for(int i=2;i<32768;i++){
//		if(i%2==0){
//			for(int j=1;j<i;j+=2){
//				if(gongyueshu(j,i)==1){
//					num[i]++;
//				}
//			}
//		}
//		else {
//			for(int j=1;j<i;j++){
//				if(gongyueshu(j,i)==1){
//					num[i]++;
//				}
//			}
//		}
//	}
	int cn;
	scanf("%d",&cn);
	while(cn--){
		memset(a,0,maxn);
		int n;
		scanf("%d",&n);
		prime();
		int ans=n;
		for(int i=2;i<=n;i++){
			if(n%i==0&&a[i]==0){
				ans*=(1-1.0/(i*1.0));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
