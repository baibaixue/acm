#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn  300005
#define inf 1e9+1 
using namespace std;
struct node{
	long long l;
	long long r;
	long long p;
	int has_son;
}tree[maxn*4];
long long find_p(long long b,int k){
	if(tree[k].has_son==0){
		return tree[k].p;
	}else if(b<=tree[k*2].r){
		return find_p(b,k*2);
	}else if(b>tree[k*2+1].l){
		return find_p(b,k*2+1);
	}
} 
void build_tree(long long a,long long b,int k){
	if(tree[k].has_son==0){
		tree[k].has_son=1;
		tree[k*2].r=a;tree[k*2].l=tree[k].l;
		tree[k*2+1].l=a+1;tree[k*2+1].r=tree[k].r;
		tree[k*2].p=min(tree[k].p,b);
		tree[k*2+1].p=tree[k].p;
	}else{
		if(a<tree[2*k].r){
			build_tree(a,b,2*k);
		}else if(a>tree[2*k].r){
			build_tree(a,b,2*k+1);
			build_tree(tree[2*k].r,b,2*k);
		}else if(a==tree[2*k].r){
			tree[2*k].p=min(tree[2*k].p,b);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++){
			tree[i].l=0;
			tree[i].r=inf;
			tree[i].p=inf;
			tree[i].has_son=0;
		}
		for(int i=0;i<n;i++){
			int p;
			long long a,b,c;
			scanf("%d",&p);
			if(p==1){
				scanf("%lld",&b);
				long long ans=find_p(b,1);
				if(find_p(b,1)==inf){
					printf("-1\n");
				}else{
					printf("%lld\n",find_p(b,1));
				}
			}if(p==0){
				scanf("%lld%lld",&a,&c);
				build_tree(a,c,1);
			}
		}
	}
}
