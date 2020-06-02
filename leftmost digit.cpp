#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double n;
		scanf("%lf",&n);
		long long int m=n*log10(n);
			double a=n*log10(n)-m;
			a=pow(10.0,a);
			if(a==0){
				printf("1\n");
			}
//			double a=n;
//				while(n>10){
//					n=n/10;
//				}
//			for(int i=0;i<a-1;i++){
//				n*=a;
//				while(n>10){
//					n=n/10;
//				}
//			}
		else{
			printf("%d\n",(int)a);
		}
	} 
	return 0;
} 
