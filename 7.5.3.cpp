#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 100005
using namespace std;
struct node{
	int root;
	node father;
	vector<node>son;
};
node tree[maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,r;
		scanf("%d%d%d",&n,&m,&r);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			tree[u].root=u;
			tree[v].root=v;
			tree[v].father=tree[u];
			tree[u].son.pushback(tree[v]);
		}
		for(int i=0;i<m;i++){
			int q;
			scanf("%d",&q);
			if(q==r){
				printf("0\n");
			}else{
				int cnt=0;
				queue<node> q;
				q.push(tree[q]);
				while(tree[q])
			}
		}
	}
} 
