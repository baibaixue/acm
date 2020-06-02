#include<stdio.h>
int palindrom(int n){
	int i;
	int x=0;
	int a,b=n;
	for(i=0;;i++){
		a=b%10;
		b/=10;
		x=x*10+a;
		if(b==0){
			break;
		}
	}
	return x;
}
int main(){
	int n;
	scanf("%d",&n);
	if(palindrom(n)==n){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}
