#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 10010
using namespace std;
long long int x[maxn],y[maxn];
double c[maxn];
int f(int  a,int n){
	return n/(a*a);
}
int main(){
	int n;
	long long int m;
	while(scanf("%lld%d",&m,&n)!=EOF){
		for(int i=0;i<m;i++){
			scanf("%d%d",x[i],y[i]);
		}
		for(int i=1;i<m;i++){
			c[i]=(x[i]-x[i-1])/(y[i]-y[i-1]);
		}
	}
}
