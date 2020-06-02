#include<stdio.h>

int main(){
	int a[100];
	int i,j,n,m,sum;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<100;i++){
			a[i]=0;
		}
		a[0]=2;
		for (i=1;i<n;i++){
			a[i]=a[i-1]+2;
		}
		scanf("%d",&m);
		for(j=0;j<n;j+=m){
			sum=0;
			for(i=j;i<j+m;i++){
				sum+=a[i];
			}
			if(j/m<n/m){
				if(j==0){
					printf("%d",sum/m);
				}else{
					printf(" %d",sum/m);
				}
			}else{
				if(n%m==0){
					printf(" %d",sum/m);
				}else{
					printf(" %d",sum/(n%m));
				}
			}
		}
		printf("\n");
	}
	return 0;
}

