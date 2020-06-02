#include<cstdio>
#include<string.h>
#include<algorithm>
#define maxn 5000
using namespace std;
int r[maxn];
struct cost{
	int s,e;
	int m;
}road[maxn];
int find(int x){
	int root=x;
	if(root==r[root]){
		return root;
	}else{
		return find(r[root]);
	}
}
void hebing(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		r[b]=a;
	}
}
int cmp(cost a,cost b){
	return a.m<b.m;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=1;i<=n;i++){
			r[i]=i;
		}
		int num=n*(n-1)/2;
		int k;
		for(int i=0;i<num;i++){
			scanf("%d%d%d%d",&road[i].s,&road[i].e,&road[i].m,&k);
			if(k==1){
				hebing(road[i].s,road[i].e);
			}
		}
		sort(road,road+num,cmp);
		int ans=0;
		for(int i=0;i<num;i++){
			if(find(road[i].s)!=find(road[i].e)){
				ans+=road[i].m;
				hebing(road[i].s,road[i].e);
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}
