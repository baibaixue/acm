#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10005
using namespace std;
int N[maxn];
int main(){
	int m,n;
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d%d",&n,&m);
		N[0]=0;
		int k=m;
		for(int i=1;i<=n;i++){
			if(k!=0){
				N[i]=1;
				k--;
			}else{
				N[i]=0;
				k=m;
			}
		}
		if(N[n]!=0){
			printf("Grass\n");
		}else{
			printf("Rabbit\n");
		}
	}
	return 0;
}
