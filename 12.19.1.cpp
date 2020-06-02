#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#define maxn 10005
using namespace std;
int city[maxn];
struct r{
	int s,e;
}road[maxn];
int find(int x){
	int r=x;
	if(r==city[r]){
		return r;
	}
	if(r!=city[r]){
		return find(city[r]);
	}
}
void he(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y){
		city[b]=a;
	} 
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
//	for(int i=1;i<maxn;i++){
//		city[i]=i;
//	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		//he(a,b);
		road[i].e=a;road[i].s=b;
	}
	int k;
	scanf("%d",&k);
	int lost[maxn];
	while(k--){
		memset(lost,0,sizeof(lost));
		for(int i=0;i<maxn;i++){
			city[i]=i;
		}
		int Np;
		int l;
		scanf("%d",&Np);
		for(int i=0;i<Np;i++){
			scanf("%d",&l);
			lost[l]=1;
		}
		for(int i=0;i<m;i++){
			if(lost[road[i].s]==0&&lost[road[i].e]==0){
				he(road[i].s,road[i].e);
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(city[i]==i){
				cnt++;
			}
		}
		if(cnt==n){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
