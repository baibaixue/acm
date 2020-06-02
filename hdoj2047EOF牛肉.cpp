#include<stdio.h>
int main(){
	int m;
	long long c[50]={0,3,8};
	while(scanf("%d",&m)!=EOF){
		for(int i=3;i<51;i++){
			c[i]=2*(c[i-1]+c[i-2]);
		}
		printf("%lld\n",c[m]);
	}
	int a,b;
	long long int n[50];
	while(~scanf("%d",&a)){	
		n[1]=3;
		n[2]=8;
		for(b=3;b<=a;b++)
		{
			n[b]=2*(n[b-2]+n[b-1]);
		}
		printf("%lld\n",n[a]);
	}
	return 0;
}

