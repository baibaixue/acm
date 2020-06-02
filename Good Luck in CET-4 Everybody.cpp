#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int num[1005];
int main(){
	int n;
	for(int i=0;i<1005;i++){
		if(i%3==0){
			num[i]=1;
		}else{
			num[i]=0;
		}
	}
	while(scanf("%d",&n)!=EOF){
		if(num[n]==1){
			printf("Cici\n");
		}else{
			printf("Kiki\n");
		}
	}
	return 0;
}
