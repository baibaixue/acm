#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 150005
using namespace std;
struct node{
	int l,r;
	int w;
	int f[55];
}tree[maxn];
int b[11][11];
void build(int l,int r,int k){
	tree[k].l=l;tree[k].r=r;
	memset(tree[k].f,0,sizeof(tree[k].f));
	if(tree[k].l==tree[k].r){
		scanf("%d",&tree[k].w);
		return ;
	}
	int m=(l+r)/2;
	build(l,m,2*k);
	build(m+1,r,2*k+1);
	tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
void down(int k,int x,int z){
		tree[k*2].f[b[z][x%z]]+=tree[k].f[b[z][x%z]];
		tree[k*2+1].f[b[z][x%z]]+=tree[k].f[b[z][x%z]];
		tree[k].f[b[z][x%z]]=0;
	//	tree[k*2].w+=c*((tree[k*2].r-tree[k*2].l+1)/z);
	//	tree[k*2+1].w+=c*((tree[k*2+1].r-tree[k*2+1].l+1)/z);
}
void quest(int k,int a){
	if(tree[k].l==a&&tree[k].r==a){
		for(int z=1;z<=10;z++){
			tree[k].w+=tree[k].f[b[z][a%z]];
			tree[k].f[b[z][a%z]]=0;
		}
		printf("%d\n",tree[k].w);
		return ;
	}
	for(int z=1;z<=10;z++){
		if(tree[k].f[b[z][a%z]]){
			down(k,a,z);
		}
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(a<=m){
		quest(2*k,a);
	}else{
		quest(2*k+1,a);
	}
}
void change(int x,int y,int c,int z,int k){
	if(tree[k].l>=x&&tree[k].r<=y){
		tree[k].f[b[z][x%z]]+=c;
		//tree[k].w+=c*((tree[k].r-tree[k].l+1)/z);
		return ;
	}
	if(tree[k].f[b[z][x%z]]){
		down(k,x,z);
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(x<=m){
		change(x,y,c,z,2*k);
	}if(y>m){
		change(x,y,c,z,2*k+1);
	}
	tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
int main(){
	int n,q;
	int t=0;
	for(int i=0;i<11;i++){
		for(int j=0;j<i;j++){
			b[i][j]=t++;
			//printf("b[%d][%d]=%d\n",i,j,b[i][j]);
		}	
		}
	while(scanf("%d",&n)!=EOF){
		tree[1].l=1;
		tree[1].r=n;
		build(1,n,1);
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int x;
			scanf("%d",&x);
			if(x==2){
				int num;
				scanf("%d",&num);
				quest(1,num);
			}
			if(x==1){
				int a,b,k,c;
				scanf("%d%d%d%d",&a,&b,&k,&c);
				change(a,b,c,k,1);
			}
		}
	}
	return 0;
} 
