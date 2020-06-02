#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		double sum_v=0;
		double X=0,Y=0;
		double x1=0,y1=0;
		double x2=0,y2=0;
		double x0=0,y0=0;
		double s=0;
		scanf("%lf%lf%lf%lf",&x0,&y0,&x1,&y1);
		for(int i=2;i<n;i++){
			scanf("%lf%lf",&x2,&y2);
			s=0.5*((x1-x0)*(y2-y0)-(x2-x0)*(y1-y0));
			sum_v+=s;
			X+=(x1+x2+x0)*s;
			Y+=(y1+y2+y0)*s;
			x1=x2;
			y1=y2;
		}
		X=X/(sum_v*3.0);
		Y=Y/(sum_v*3.0);
		printf("%.2lf %.2lf\n",X,Y);
	}
	return 0;
}
