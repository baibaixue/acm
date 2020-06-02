#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double f(double x){
	return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double y;
		scanf("%lf",&y);
		double a=0,b=100;
		if(f(0)>y||f(100)<y){
			printf("No solution!\n");
		}
		else{
			double m;
			while(b-a>1e-6){
				m=(a+b)/2.0;
				if(f(m)>y){
					b=m-1e-7;
				}if(f(m)<y){
					a=m+1e-7;
				}
			}
			printf("%.4f\n",b);
		}
	}
	return 0;
} 
