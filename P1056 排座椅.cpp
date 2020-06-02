#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10005
using namespace std;
int M[maxn];
int N[maxn];
int main(){
	int m,n,k,l,d;
	int lenm=0,lenn=0;
	scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
	for(int i=0;i<d;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==b){
			M[lenm++]=min(b,d);
		}if(c==d){
			N[lenn++]=min(a,c);
		}
	}
	sort(M,M+lenm);
	sort(N,N+lenn);
	printf("%d",M[0]);
	for(int i=1;i<lenm;i++){
		printf(" %d",M[i]);
	}
	printf("\n");
	printf("%d",N[0]);
	for(int i=1;i<lenn;i++){
		printf(" %d",N[i]);
	}
	printf("\n");
	return 0;
}
