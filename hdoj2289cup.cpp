#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define pi 3.1415926535
using namespace std;
double r,R,H,V;
double vol_t(double h){
	double u = r + ( R- r ) * h / H;
 	return (  3.1415926535897932384626433832795* h * (u* u + r * u + r * r) / 3.0 );

}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf%lf%lf",&r,&R,&H,&V);
		double a=0,b=H;
		double m=(a+b)/2.0;
		while(b-a>1e-10){
			m=(a+b)/2.0;
			if(vol_t(m)>V){
				b=m-1e-11;
			}if(vol_t(m)<V){
				a=m+1e-11;
			}if(vol_t(m)==V){
				a=m;b=m;
				break;
			}
		}
		printf("%f\n",b);
	}
	return 0;
}
