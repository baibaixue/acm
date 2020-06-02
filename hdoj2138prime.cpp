#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int count=0;
		while(n--){
			int k=1;
			long long int x;
			scanf("%lld",&x);
			for(int i=2;i<=sqrt(x);i++){	 
				if(x%i==0){
					k=0;
					break;
				}
			}
				if(k==1){
					count++;
				}
		}
		printf("%d\n",count);
	}
	return 0;
}
