#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1000000
using namespace std;
int n[maxn+5];
int main(){
	int N,m;
	int a; 
	memset(n,0,sizeof(n));
	while(scanf("%d%d",&N,&m)!=EOF){
		for(int i=0;i<N;i++){
			scanf("%d",&a);
			a=a+maxn/2;
			n[a]=1;
		}
		for(int i=maxn;m!=0;i--){
			if(n[i]==1){
				printf("%d",i-maxn/2);
				m--;
				if(m!=0){
					printf(" ");
				}else{
					printf("\n");
				}
			}
		}
	}
	return 0;
} 
