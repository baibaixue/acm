#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long L,R;
		scanf("%lld%lld",&L,&R);
		int a=(L-1)/192+1;
		int b=(R-1)/192+1;
		long long l=a*192+1;
		long long r=(b-1)*192+1;
		int ans=0;
		ans=b-a;
		if(L%192==1){
			ans+=1;
			l=L;
		}
		long long res=0;
		res=(l+r)*ans/2;
		printf("%lld\n",res);
	}
	return 0;
}
