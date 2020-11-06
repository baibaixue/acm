#include<stdio.h>//多项式求和 11月19日 白雪
double fact(int n){//求阶乘 
	int i;
	double ans=1;
	for(i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
} 
double mypow(double x,int n){//求x的N次幂 
	int i;
	double ans=1;
	for(i=1;i<=n;i++){
		ans*=x;
	}
	return ans;
}
int main(){
	int n;
	double x;
	scanf("%lf%d",&x,&n);
	int i;
	double a=0;
	double sum=0;
	for(i=1;i<=n;i++){
		a=mypow(-1.0,n+1)*mypow(x,n);//第n项 
		sum+=a;//n项相加 
	}
	printf("%f\n",sum);
	return 0;
} 
