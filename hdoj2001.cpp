#include<stdio.h>
#include<math.h>
double pow(double a,double b);
int main()
{
	double x1,y1,x2,y2;
	double res;
	double a=2.0;
	while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF){
	res=pow((x2-x1),a)+pow((y2-y1),a);
	printf("%.2f\n",sqrt(res));
}
	return 0;
}
