#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<cmath>
#define maxn 100005
#define pi 3.14
using namespace std;
double my_max(double a,double b){
	if(a>b){
		return a;
	}else{
		return b;
	}
} 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int max_a=0;
		double max_r=0.0;
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			max_a=max(max_a,(int)max((int)fabs(a),(int)fabs(b)));
			max_r=my_max(max_r,sqrt(1.0*a*a+b*b));
		}
		double s1=pi*max_r*max_r;
		int s2=(max_a*2)*(max_a*2);
		printf("%d\n%d\n",(int)(s1+0.5),s2);
	}
	return 0;
}
