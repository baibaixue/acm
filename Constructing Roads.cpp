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
void hebing(int x,int y){
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
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<maxn*maxn;i++){
			road[i].m=0;
		}
		int k=0;
		for(int i=0;i<=maxn;i++){
			v[i]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				road[k].s=i;
				road[k].e=j;
				scanf("%d",&road[k].m);
				k++;
			}
		}
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			hebing(x,y);
		}
		sort(road,road+k,cmp);
		int sum=0;
		for(int i=0;i<k;i++){
			int aa=find(road[i].s);
			int bb=find(road[i].e);
			if(aa!=bb){
				sum+=road[i].m;
				hebing(aa,bb);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
