#include<stdio.h>

int main(){
	int m,n,i,j,x;
	double sum;
	while(scanf("%d",&m)!=EOF){
		for(i=0;i<m;i++){
			scanf("%d",&n);
			for(j=1;j<n+1;j++){
				if(j%2==0){
					x=-1;
				}else{
					x=1;
				}
				sum+=x*1.0/j;
			}
			printf("%.2f\n",sum);
			sum=0;
		}
	}
	return 0;
}
