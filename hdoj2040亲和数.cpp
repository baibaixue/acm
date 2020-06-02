#include<stdio.h>
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
int main(){
	int m;
	int a,A,b,B;
	while(scanf("%d",&m)!=EOF){
		while(m--){
			A=0;B=0;
			scanf("%d%d",&a,&b);
			for(int i=1;i<=max(a/2,b/2)&&i!=a&&i!=b;i++){
				if(a%i==0){
					A+=i;
				}
				if(b%i==0){
					B+=i;
				}
			}
			if(A==b&&B==a){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
} 
