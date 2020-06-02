#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#define maxn 50
using namespace std;
int num[maxn];
int main(){
	int a,b;
	long long n;
	while(scanf("%d%d%lld",&a,&b,&n)!=EOF&&a&&b&&n){
		for(int k=1;k<=50;k++){
			if(k==1||k==2){
				num[k]=1;
			}else{
				num[k]=(a*num[k-1]+b*num[k-2])%7;
			}
		}
		printf("%d\n",num[n%48]);
	} 
}
