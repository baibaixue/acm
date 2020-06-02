#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define inf 0x3f3f3f3f
#define maxn 150
using namespace std;
int p[maxn];
double pi[maxn];
double s(double pi){
//	int n=2;
//	double ans=0;
//	while(n*pow(pi,2)*pow(1.0-pi,n-2)>1e-6){
//		ans+=n*pi*pi*pow((1-pi),n-2.0);
//		n++;
//	}
//	return ans;
	return (1.0-pi*pi)/(1.0-pi);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
			sum+=p[i];
		}
		for(int i=0;i<n;i++){
			pi[i]=p[i]*1.0/sum;
		}
		double S=0;
		for(int i=0;i<n;i++){
			S+=s(pi[i]);
		}
		//printf("%.lf\n",S);
		long long ans=(long long)(S+0.5);
		printf("%lld\n",ans%1000003);
	}
}
