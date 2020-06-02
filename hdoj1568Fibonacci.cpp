#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int c[21];
int main(){
	int n;
	c[0]=0;c[1]=1;
	for(int i=2;i<21;i++){
		c[i]=c[i-1]+c[i-2];
	}
	while(scanf("%d",&n)!=EOF){
		if(n<21){
			printf("%d\n",c[n]);
		}
		else{
			double ans=n*log10((1+sqrt(5.0))/2.0)-log10(sqrt(5.0));
			ans=ans-(int)ans;
			ans=pow(10.0,ans);
			while(ans<1000){
				ans=ans*10;
			}
			printf("%d\n",(int)ans);
		}
	}
	return 0;
} 
