#include<stdio.h>
int main(){
	long long int r,e,c;
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%lld%lld%lld",&r,&e,&c);
		if(r==(e-c)){
			printf("does not matter");
		}else if(r<(e-c)){
			printf("advertise");
		}else{
			printf("do not advertise");
		}
		printf("\n");
	}
	return 0;
} 
