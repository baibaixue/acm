#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
		if((n-1)%2==1){
			printf("Wonderful!\n");
		}else if((m-1)%2==0){
			printf("What a pity!\n");
		}else{
			printf("Wonderful!\n");
		}
	}
	return 0;
}  
