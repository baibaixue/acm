#include<cstdio>
#include<string.h>
int a[10];
int same(long long n){
	memset(a,0,sizeof(a));
	for(int i=0;i<9;i++){
		a[n%10]=1;
		n=n/10;
	}
	for(int i=1;i<=9;i++){
		if(a[i]==0){
			return 0;
		}
	}
	return 1;
} 
int main(){
	int a,b,c;
	int ok=0;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<999;i+=a){
		if(i>100&&i/a*b<999&&i/a*c<999){
			long long x;
			x=i*1000000+i/a*b*1000+i/a*c;
			if(same(x)==1){
				ok=1;
				printf("%d %d %d\n",i,i/a*b,i/a*c);
			}
		}
	}
	if(ok==0){
		printf("No!!!\n");
	}
	return 0;
}
