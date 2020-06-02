#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define maxn 
#define inf 0x3f3f3f3f
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long a,b,c;
		long long k;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
			for(long long i=0;i<k;i++){
				if(a>b){
					a=a-b;
				}
				if(b>c){
					b=b-c;
				}
				if(c>a){
					c=c-a;
				}
				if(a==b&&b==c){
					break;
				}
		}
		printf("%lld %lld %lld\n",a,b,c);
	}
}
