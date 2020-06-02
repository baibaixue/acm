#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define pi acos(-1)
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		double ans;
		if(n<=0){
			printf("Impossble\n");
		}else{
			ans=0.5*n*n/pi;
			printf("%.8f\n",ans);
		}	
	}
	return 0;
}
