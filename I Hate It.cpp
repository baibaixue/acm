#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 800005
using namespace std;
struct node{
	int l,r;
	int w;
}tree[maxn];
int max_score;
void build(int l,int r,int k){
	tree[k].l=l;tree[k].r=r;
	if(tree[k].l==tree[k].r){
		scanf("%d",&tree[k].w);
		return ;
	}
	int m=(l+r)/2;
	build(l,m,k*2);
	build(m+1,r,k*2+1);
	if(tree[k*2].w>tree[k*2+1].w){
		tree[k].w=tree[k*2].w;
	}else{
		tree[k].w=tree[k*2+1].w;
	}
}
void quest(int l,int r,int k){
	if(tree[k].l>=l&&tree[k].r<=r){
		if(tree[k].w>max_score){
			max_score=tree[k].w;
		}
		return ;
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(r>m){
		quest(l,r,2*k+1);
	}if(l<=m){
		quest(l,r,2*k);
	}
	
}
void change(int x,int y,int k){
	if(tree[k].l==tree[k].r&&tree[k].l==x){
		tree[k].w=y;
		return ;
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(x<=m){
		change(x,y,2*k);
	}else{
		change(x,y,2*k+1);
	}
	if(tree[k*2].w>tree[k*2+1].w){
		tree[k].w=tree[k*2].w;
	}else{
		tree[k].w=tree[k*2+1].w;
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		build(1,n,1);
		char c;
		for(int i=0;i<m;i++){
			int a,b;
			getchar();
			scanf("%c",&c);
			scanf("%d%d",&a,&b);
			if(c=='Q'){
				max_score=0;
				quest(a,b,1);
				printf("%d\n",max_score);
			}
			if(c=='U'){
				change(a,b,1);
			}
		}
	}
	return 0;
}
