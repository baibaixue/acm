#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define pi acos(-1)
#define g 9.8
using namespace std;
double b_search(double x,double y,double v){
	double l=0,r=pi/2;
	double m;
	while(r-l>1e-8){
		m=(l+r)/2;
		double mid=x*tan(m)-g*x*x/(2.0*v*v*sin(m)*sin(m));
		if(mid==y){
			return m;
		}else if(mid>y){
			l=m+1e-8;
		}else{
			r=m-1e-8;
		}
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double x,y,v;
		scanf("%lf%lf%lf",&x,&y,&v);
//		double ans=b_search(x,y,v);
//		if(ans==-1.0){
//			printf("-1\n");
//		}else{
//			printf("%.6f\n");
//		}
	}
	return 0;
}
