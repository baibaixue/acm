#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 10000+50
#define pi 3.1415926
using namespace std;
double V[maxn];
double v(int r){
	return r*r*pi;
}
double basearch(int ri,int f){
	double l=0,r=v(ri);
	double m;
	while(r-l>1e-6){
		m=(r+l)/2.0;
		if(m*f>v(ri)){
			r=m-1e-6;
		}else{
			l=m+1e-6;
		}
	}
	return r;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,f;
		scanf("%d%d",&n,&f);
		f=f+1;
		for(int i=0;i<n;i++){
			double ri;
			scanf("%d",&ri);
			V[i]=v(ri);
		}
		sort(V,V+n);
		double sum=0;
		for(int i=0;i<n;i++){
			sum+=basearch(r[i],f);
		}
		printf("%.4f\n",sum);
	}
	return 0;
}
