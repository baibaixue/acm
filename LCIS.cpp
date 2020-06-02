#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 400005
using namespace std;
struct node{
	int lmax,rmax;
	int l,r;
	int w;
}tree[maxn];
int ans;
int N[100005];
void build(int l,int r,int k){
	tree[k].l=l;tree[k].r=r;
	if(tree[k].l==tree[k].r){
		tree[k].lmax=1;
		tree[k].rmax=1;
		tree[k].w=1;
		return ;
	}
	int m=(l+r)/2;
	build(l,m,2*k);
	build(m+1,r,2*k+1);
	tree[k].lmax=tree[2*k].lmax;
	tree[k].rmax=tree[k*2+1].rmax;
	tree[k].w=max(tree[2*k].w,tree[2*k+1].w);
	if(N[tree[2*k].r]<N[tree[2*k+1].l]){
		if(tree[2*k].lmax==tree[2*k].r-tree[2*k].l+1){
			tree[k].lmax+=tree[2*k+1].lmax;
		}if(tree[2*k+1].rmax==tree[2*k+1].r-tree[k*2+1].l+1){
			tree[k].rmax+=tree[k*2].rmax;
		}
		tree[k].w=max(tree[k*2].rmax+tree[k*2+1].lmax,tree[k].w);
	}
	tree[k].w=max(tree[k].w,max(tree[k].lmax,tree[k].rmax));
}
void change(int k,int a){
	if(tree[k].l==a&&tree[k].r==a){
		return ;
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(a<=m){
		change(k*2,a);
	}else{
		change(k*2+1,a);
	}
	tree[k].lmax=tree[2*k].lmax;
	tree[k].rmax=tree[k*2+1].rmax;
	tree[k].w=max(tree[2*k].w,tree[2*k+1].w);
	if(N[tree[2*k].r]<N[tree[2*k+1].l]){
		if(tree[2*k].lmax==tree[2*k].r-tree[2*k].l+1){
			tree[k].lmax+=tree[2*k+1].lmax;
		}if(tree[2*k+1].rmax==tree[2*k+1].r-tree[k*2+1].l+1){
			tree[k].rmax+=tree[k*2].rmax;
		}
		tree[k].w=max(tree[k*2].rmax+tree[k*2+1].lmax,tree[k].w);
	}
	tree[k].w=max(tree[k].w,max(tree[k].lmax,tree[k].rmax));
}
int quest(int k,int a,int b){
	if(tree[k].l>=a&&tree[k].r<=b){
		return tree[k].w;
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(b<=m){
		return quest(2*k,a,b);
	}
	else if(a>m){
		return quest(2*k+1,a,b);
	}else{
		int m1,m2,t1=0,t2=0;
		m1=quest(k*2,a,b);
		m2=quest(k*2+1,a,b);
		if(N[tree[k*2].r]<N[tree[k*2+1].l]){
			t1=min(m-a+1,tree[k*2].rmax);
			t2=min(b-m,tree[k*2+1].lmax);
		}
		return max(max(m1,m2),t1+t2);
	}
}
int main(){
	int n,m;
	int t;
	scanf("%d",&t);
	while(t--){
		memset(N,0,sizeof(N));
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&N[i]);
		}
		build(0,n-1,1);
		for(int i=0;i<m;i++){
			char c[10];
			int a,b;
			scanf("%s",c);
			scanf("%d%d",&a,&b);
			if(c[0]=='Q'){
				ans=quest(1,a,b);
				printf("%d\n",ans);
			}
			if(c[0]=='U'){
				N[a]=b;
				change(1,a);
			}
		}
	}
	return 0;
}
