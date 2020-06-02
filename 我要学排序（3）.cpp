#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int M[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int c;
	scanf("%d",&c);
	while(c--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&M[i]);
		}
		sort(M,M+n,cmp);
		for(int i=0;i<m;i++){
			printf("%d ",M[i]);
		}
		printf("\n");
	}
} 
