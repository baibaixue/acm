#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define inf 0f3x3x3x3x
#define maxn 
using namespace std;
int main(){
	double pi=1.0/5000.0;
	double ans=0;
	for(int i=2;;i++){
		double a=i*pi*pi*pow((1-pi),i-2);
		ans+=a;
		if(a<1e-12){
			break;
		}
	}
	printf("%lf\n",ans);
	printf("%lf\n",-(pi*pi-1)/(1-pi));
}
