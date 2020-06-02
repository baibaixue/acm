#include<stdio.h>
int main(){
	long long int n,m;
	double sum=0.0;
	int k=1;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		if(n!=0&&m!=0){
			for(int j=n;j<=m;j++){
				sum+=1.0/j/j;
			}
		printf("Case %d:\n",k);
		k++;
		printf("%.5f\n",sum);
		sum=0.0;
		}
		else{
			break;
		}
	}
	return 0;
} 
