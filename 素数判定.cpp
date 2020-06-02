#include<stdio.h>
#include<math.h>
int is_prime(int n){
	int m;
	m=floor(sqrt(n)+0.5);
	for(int i=2;i<=m;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	while(scanf("%d",&n)!=0){
		if(is_prime(n)!=0){
			printf("OK\n");
		}else{
			printf("no\n");
		}
	}
	return 0;
}
