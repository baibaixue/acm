#include<cstdio>
#include<cmath>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a=1;
		for(int i=0;i<n;i++){
			a*=2;
		}
		printf("2^%d = %d\n",n,a);
	}
	return 0;
} 
