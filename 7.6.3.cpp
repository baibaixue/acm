#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define inf 0f3x3x3x3x
#define maxn 
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		long long p=z*(z+x)*(z+y);
		long long q=(z+x)*z+(z+y)*z-(z+x)*(z+y);
		if(q<=0){
			printf("Impossible\n");
		}else{
			long long a;
			long long A=max(p,q);
			long long B=min(p,q); 
			while(B!=0){
				a=A%B;
				A=B;
				B=a;
			}
			printf("%lld %lld\n",p/A,q/A);
		}
	} 
}
