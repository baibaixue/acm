#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		double x;
		if(n<=150){
			x=n*0.4463;
		}else if(n>150&&n<=400){
			x=150*0.4463+(n-150)*0.4663;
		}else if(n>400){
			x=150*0.4463+(400-150)*0.4663+(n-400)*0.5663;
		}
		printf("%.1f\n",x);
	}
	return 0;
}
