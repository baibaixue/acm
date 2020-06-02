#include<stdio.h>
int digit(int n,int k){
	int i;
	int x=n;
	for(i=1;i<k;i++){
		x=x/10;
	}
	if(x=0){
		return 0;
	}
	else
	return x%10;
} 
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d",digit(n,k));
	return 0;
}
