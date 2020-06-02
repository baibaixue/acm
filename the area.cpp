#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double a,b,c,k,q;
double f(double x){
	return (1.0/3.0)*a*x*x*x+(1.0/2.0)*b*x*x+c*x-(1.0/2.0)*k*x*x-q*x;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double x1,y1,x2,y2,x3,y3;
		scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
		k=(y3-y2)/(x3-x2);
		q=y2-k*x2;
		a=(y2-y1)/((x2-x1)*(x2-x1));
		b=(-2)*a*x1;
		c=x1*x1*a+y1;
		double ans;
		ans=f(x3)-f(x2);
		printf("%.2f\n",ans);
	} 
	return 0;
}
