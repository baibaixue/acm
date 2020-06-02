#include<cstdio>
int main(){
	long long n;
	while(scanf("%lld",&n)!=EOF){
//		while(n>18){
//			n=n/18;
//		}
//		if(n<=9){
//			printf("Stan wins.\n");
//		}else{
//			printf("Ollie wins.\n");
//		}
		int t=1;
		long long l=2,r=9;
		while(!(n<=r&&n>=l)){
			t=-t;
			l=r+1;
			r=r*18;
			if(t==-1){
				r=r/9;
			}else{
				r=r/2;
			}
		}
		if(t==-1){
			printf("Ollie wins.\n");
		}else{
			printf("Stan wins.\n");
		}
	}
	return 0;
}
