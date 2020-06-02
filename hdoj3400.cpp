#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double distance(int a,int b,int c,int d){
	return sqrt(fabs(a-c)*fabs(a-c)+fabs(b-d)*fabs(b-d));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
		int p,q,r;
		scanf("%d%d%d%d%d%d%d%d",&Ax,&Ay,&Bx,&By,&Cx,&Cy,&Dx,&Dy);
		scanf("%d%d%d",&p,&q,&r);
		double n=distance(Ax,Ay,Bx,By)/p*1.0+distance(Bx,By,Dx,Dy)/r*1.0;
		double l=distance(Ax,Ay,Cx,Cy)/r*1.0+distance(Cx,Cy,Dx,Dy)/q*1.0;
		double m=distance(Ax,Ay,Dx,Dy)/r*1.0;
		double minn=min(n,l);
		minn=min(minn,m);
		printf("%.2f\n",minn);
	}
	return 0;
} 
