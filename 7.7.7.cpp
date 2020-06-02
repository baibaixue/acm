#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define maxn 100005
#define inf 0x3f3f3f3f
using namespace std;
long long num[maxn];
int main(){
	for(int i=0;i*i<=1000000000;i++){
		num[i]=2*i*(i+1);
	}
	int T;
	scanf("%d",&T);
	while(T--){
		long long a;
		scanf("%lld",&a);
		long long ans=0;
		long long b=(long long)sqrt(a);
		ans=num[b]+2*(a-b*b);
		if(a-b*b!=0){
			if(a-b*b<=b){
				ans++;
			}else{
				ans+=2;
			}
		}
		
		printf("%lld\n",ans);
	} 
}
