#include<stdio.h>
	#define pi 3.1415926
int main()
{
	double r,h,V;
	printf("please input radium and hight:");
	scanf("%lf%lf",&r,&h);
	V=pi*r*r*h;
	printf("V=%f",V);
	return 0;
}
