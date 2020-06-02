#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int main(){
	int z,n,maxn,sum,a,b,A,B,t;
	scanf("%d",&z);
	for(int i=1;i<=z;i++){
		scanf("%d",&n);
		sum=maxn=-1001;
		for(int j=1;j<=n;j++){
			scanf("%d",&t);
			if(sum+t<t){
				sum=t,a=b=j;
			}
			else{
				sum+=t,++b;
			}
			if(maxn<sum){
				maxn=sum,A=a,B=b;
			}
		}
		printf("Case %d:\n%d %d %d\n",i,maxn,A,B);
		if(i!=z){
			printf("\n");
		}
	}
	return 0;
}
