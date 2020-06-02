#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
struct nn{
	char num[15];
}mm[1005];
char num[15];
int n[1005];
int m[1005];
int main(){
	int N,M;
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		scanf("%s",mm[i].num);
		scanf("%d%d",&n[i],&m[i]);
		getchar();
	}
	int k;
	scanf("%d",&k);
	while(k--){
		int q;
		scanf("%d",&q);
		for(int i=0;i<N;i++){
			if(n[i]==q){
				q=i;
				break;
			}
		}
		printf("%s %d\n",mm[q].num,m[q]);
	}
	return 0;
} 
