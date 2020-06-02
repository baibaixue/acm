#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 5005
using namespace std;
struct num{
	int s;
	int k;
}n[maxn];
int cmp(num a,num b){
	if(a.s==b.s){
		return a.k<b.k;
	}else{
		return a.s>b.s;
	}
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d%d",&n[i].k,&n[i].s);
	}
	M=M*3/2;
	sort(n,n+N,cmp);
	int score=n[M-1].s;
	for(int i=M;n[i].s==score;i++){
		M++;
	}
	printf("%d %d\n",score,M);
	for(int i=0;i<M;i++){
		printf("%d %d\n",n[i].k,n[i].s);
	}
	return 0;
} 
