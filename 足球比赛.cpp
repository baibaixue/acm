#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<cmath>
#define maxn 1050
using namespace std;
int N[maxn];
struct node{
	int l;int r;
	bool w;
}tree[maxn*4];
int ans;
void build(int l,int r,int k){
	tree[k].l=l;tree[k].r=r;
	if(tree[k].l==tree[k].r){
		if(N[tree[k].l]==0){
			tree[k].w=true;
		}else{
			tree[k].w=false;
		}
		return ;
	}
	int m=(l+r)/2;
	build(l,m,2*k);
	build(m+1,r,2*k+1);
	if(tree[2*k].w==true&&tree[2*k+1].w==true){
		tree[k].w=true;
	}else if(tree[2*k].w==false&&tree[2*k+1].w==true||tree[2*k].w==true&&tree[2*k+1].w==false){
		ans++;
		tree[k].w=true;
	}else{
		tree[k].w=false;
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(N,0,sizeof(N));
		ans=0;
		for(int i=1;i<=m;i++){
			int a;
			scanf("%d",&a);
			N[a]=1;
		}
		build(1,pow(2,n),1);
		printf("%d\n",ans);
	}
	return 0;
}
