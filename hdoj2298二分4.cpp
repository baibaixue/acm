#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define pi acos(-1)
#define g 9.8
using namespace std;
double x,y,v;
int s(double a,double b){
	return cos(a)*v*b-(1.0/2.0)*g*b*b;
}
int angle(double a,double b,double c){
	double l=0.0,r=pi/2.0;
	double m;
	while(l-r>1e-8){
		double m=(l+r)/2.0;
		double ti=x/sin(m)*c;
		if(s(m,ti)==y){
			printf("%f",m);
			return 0;
		}if(s(m,ti)<y){
			l=m;
		}else{
			r=m;
		}
	}
	return 0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf%lf",&x,&y,&v);
		if(angle(x,y,v)==0){
			printf("-1\n");
		}
	}
	return 0;
}
