#include<stdio.h>
#define PI 3.1415927
int main()
{
	double r,v;
	double a=3.0;
	while(scanf("%lf",&r)!=EOF){
	v=(4.0/3.0)*PI*r*r*r;
	printf("%.3f\n",v);
}
	return 0;
	
}
