#include<stdio.h>
#include<math.h> 
int main(){
	const double pi=3.1415926;
	double n;
	scanf("%lf",&n); 
	n=n*(pi/180);
	printf("%.3f %.3f\n",sin(n),cos(n));
	return 0; 
}
