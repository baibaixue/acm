#include<stdio.h>
#include<math.h>
int main()
{
	double a;
	while(scanf("%lf",&a)!=EOF){
		a=fabs(a);
		printf("%.2f\n",a);
}
	return 0;
 } 
