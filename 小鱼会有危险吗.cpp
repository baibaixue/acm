#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	double s,x;
	scanf("%lf%lf",&s,&x);
	double a=7.0;
	double S=0;
	for(int i=0;S<(s-x);i++){
		S+=a;
		a=a*0.98;
	}
	S+=a;
	if(S-(s-x)>x*2){
		printf("n\n");
	}else{
		printf("y\n");
	}
	return 0;
}
