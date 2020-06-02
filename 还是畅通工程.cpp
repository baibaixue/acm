#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 105
using namespace std;
struct cost{
	int s;
	int e;
	int m;
}road[maxn*maxn];
int v[maxn];
int find(int x){
	int r=x;
	if(r==v[r]){
		return x;
	}else{
		return find(v[r]);
	}
}
void merge(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		v[b]=a;
	}
}
int cmp(cost a,cost b){
	return a.m<b.m;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<=n;i++){
			v[i]=i;
		}
		for(int i=0;i<n*(n-1)/2;i++){
			scanf("%d%d%d",&road[i].s,&road[i].e,&road[i].m);
		}
		sort(road,road+n*(n-1)/2,cmp);
		int ans=0;
		for(int i=0;i<n*(n-1)/2;i++){
			if(find(road[i].s)!=find(road[i].e)){
				ans+=road[i].m;
				merge(road[i].s,road[i].e);
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
}
