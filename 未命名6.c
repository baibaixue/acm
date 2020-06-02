#include <stdio.h>
#include<math.h>
long long int j(int n){
	int i;
	int ans=1;
	for(i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
}
int main ()
{
	double x,eps;
	int i;
	double sum;
	while(scanf("%lf%lf",&x,&eps)!=EOF){
		double a;
		sum=1;
		for(i=1;;i++){
			a=pow(x,(double)i)/j(i);
			if(a>=eps){
				if(i%2==1){
					a=-a;
				}
				sum+=a;
			}else{
				if(i%2==1){
					a=-a;
				}
				sum+=a;
				break;
			}
		}
		printf("%.3f\n",sum);
	}
  return 0;
}

