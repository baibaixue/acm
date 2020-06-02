#include<stdio.h>
unsigned long lower(unsigned a,unsigned b){
	unsigned m,n;
	m=a;n=b;
	unsigned long c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	return m*n/b;
}
int main(){
	int n;
	unsigned a,b;
	while(scanf("%d",&n)!=EOF){
		b=1;
		while(n--){
			scanf("%ld",&a);
			b=lower(a,b);
		}
		printf("%d\n",b);
	}
	return 0;
}
