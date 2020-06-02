#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int k=0;
		int i=1;
		while(i<=n){
			int x=0;
			x=(i-k+1)/2;
			if(x>1){
				i=i+x;
				k=k+2*x;
				if(i+x>n){
					k=(k+2)%n+1;
				}else{
					k=(k+2)%i+1;
				}
			}else{
				k=(k+2)%i+1;
				i++;
			}
		}
		printf("%d\n",k);
	}
	return 0;
} 
