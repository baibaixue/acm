#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1005
using namespace std;
struct S{
	int n;
	int w,v;
}mouse[maxn];
int dp[maxn];
int ans[maxn];
int cmp(S a,S b){
	return a.w<b.w;
}
int main(){
	int W,V;
	int num;
	for(num=0;scanf("%d%d",&W,&V)!=EOF;num++){
		mouse[num].w=W;mouse[num].v=V;
	}
	sort(mouse,mouse+num,cmp);
	memset(dp,0,sizeof(dp));
	int k=0;
	for(int i=0;i<num;i++){
		for(int j=)
	}
}
