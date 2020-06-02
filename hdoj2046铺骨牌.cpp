#include<stdio.h>
int main(){
	int n;
	long long c[55]={0,1,2,3}; 
	while(scanf("%d",&n)!=EOF){
		for(int i=4;i<51;i++){
			c[i]=c[i-1]+c[i-2];
		}
		printf("%lld\n",c[n]);
	}
	return 0;
}
