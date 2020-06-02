#include<cstdio>
#include<cmath>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int k=0,a;
		for(;;){
			a=n%2;
			if(a==0){
				k++;
			}else{
				break;
			}
			n=n/2;
		}
		printf("%.0f\n",pow(2.0,(double)k));
	}
	return 0;
}
