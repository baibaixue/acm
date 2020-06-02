#include<stdio.h>
int main(){
	double m;
	while(scanf("%lf",&m)!=EOF){
		double sum=m;
		for(int i=0;i<11;i++){
			scanf("%lf",&m);
			sum+=m;
		}
		printf("$%.2f\n\n",sum/12.0);
	} 
	return 0;
} 
