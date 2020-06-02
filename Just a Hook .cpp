#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 400005
using namespace std;
struct node{
	int l,r,w,f;
}tree[maxn];
void build(int l,int r,int k){
	tree[k].f=0;
	tree[k].l=l;tree[k].r=r;
	if(tree[k].l==tree[k].r){
		tree[k].w=1;
		return ;
	}
	int m=(l+r)/2;
	build(l,m,2*k);
	build(m+1,r,2*k+1);
	tree[k].w=tree[2*k].w+tree[2*k+1].w;
}
void down(int k){
	tree[2*k].f=tree[k].f;
	tree[2*k+1].f=tree[k].f;
	tree[2*k].w=tree[k*2].f*(tree[2*k].r-tree[k*2].l+1);
	tree[2*k+1].w=tree[k*2+1].f*(tree[2*k+1].r-tree[2*k+1].l+1);
	tree[k].f=0;
} 
void change(int x,int y,int z,int k){
	if(tree[k].l>=x&&tree[k].r<=y){
		tree[k].f=z;
		tree[k].w=z*(tree[k].r-tree[k].l+1);
		return ;
	}
	if(tree[k].f) down(k);
	int m=(tree[k].l+tree[k].r)/2;
	if(x<=m){
		//printf("tree[%d].l=%d tree[%d].r=%d tree[%d].w=%d tree[%d].f=%d\n",k,tree[k].l,k,tree[k].r,k,tree[k].w,k,tree[k].f);
		change(x,y,z,k*2);
	}if(y>m){
	//	printf("tree[%d].l=%d tree[%d].r=%d tree[%d].w=%d tree[%d].f=%d\n",k,tree[k].l,k,tree[k].r,k,tree[k].w,k,tree[k].f);
		change(x,y,z,k*2+1);
	}
	tree[k].w=tree[k*2].w+tree[2*k+1].w;
//	printf("tree[%d].l=%d tree[%d].r=%d tree[%d].w=%d tree[%d].f=%d\n",k,tree[k].l,k,tree[k].r,k,tree[k].w,k,tree[k].f);
	
}
//void ans(int k){
//	if(tree[k].l==tree[k].r){
//		if(tree[k].f)
//		tree[k].w=tree[k].f;
//		return ;
//	}
//	ans(k*2);
//	ans(k*2+1);
//	tree[k].w=tree[k*2].w+tree[2*k+1].w;
//}
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		int n;
		scanf("%d",&n);
		build(1,n,1);
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int a,b,z;
			scanf("%d%d%d",&a,&b,&z);
			change(a,b,z,1);
		}
	//	ans(1);
		printf("Case %d: The total value of the hook is %d.\n",T,tree[1].w);
	}
	return 0;
} 
