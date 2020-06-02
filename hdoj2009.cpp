#include<stdio.h>
#include<math.h>
int main()
{
	double sqrt(double n);
	int n,m,i;
	double sum;
	double x;
	while(scanf("%d %d",&n,&m)!=EOF){
		sum=0.0;
		x=0.0;
		sum+=n;
		x=n;
		for(i=1;i<m;i++){
			x=sqrt(x);
			sum+=x;
		}
		printf("%.2f\n",sum);

	}
	return 0;
}
