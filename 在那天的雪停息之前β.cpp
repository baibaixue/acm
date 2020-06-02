#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		while(n!=1){
			if(n%2==0){
				printf("%d/2=",n);
				n=n/2;
				printf("%d\n",n);
			}else{
				printf("%d*3+1=",n);
				n=n*3+1;
				printf("%d\n",n);
			}
		}
		if(t!=0){
			printf("\n");
		}
	}
	return 0;
}
