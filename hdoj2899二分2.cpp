#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double f1(double x){
	return 42*pow(x,6.0)+48*pow(x,5.0)+21*pow(x,2.0)+10*x;
}
double f(double x,double y){
	return 6*pow(x,7.0)+8*pow(x,6.0)+7*pow(x,3.0)+5*pow(x,2.0)-y*x;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double y;
		scanf("%lf",&y);
		double a=0,b=100;
		if(f1(0)>y||f1(100)<y){
			printf("No solution!\n");
		}
		else{
			double m;
			while(b-a>1e-6){
				m=(a+b)/2.0;
				if(f1(m)>y){
					b=m-1e-7;
				}if(f1(m)<y){
					a=m+1e-7;
				}
			}
			printf("%.4f\n",f(b,y));
		}
	}
	return 0;
} 
