#include<stdio.h>//����ʽ��� 11��19�� ��ѩ
double fact(int n){//��׳� 
	int i;
	double ans=1;
	for(i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
} 
double mypow(double x,int n){//��x��N���� 
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
		a=mypow(-1.0,n+1)*mypow(x,n);//��n�� 
		sum+=a;//n����� 
	}
	printf("%f\n",sum);
	return 0;
} 
