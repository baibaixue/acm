#include<stdio.h>
int main(){
	int m,n,i,t;
	int a=0,b=0;
	while(scanf("%d %d",&m,&n)!=EOF){
		if(m>n){
			t=m;
			m=n;
			n=t;
		}
		for(i=m;i<=n;i++){
			if(i%2==0){
				a+=i*i; 
			}else{
				b+=i*i*i;
			}
		}
		printf("%d %d\n",a,b);
		a=0,b=0;
	}
	return 0;
}
