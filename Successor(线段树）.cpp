#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector> 
using namespace std;
struct node{
	int pre;
	int abi;
	int loy;
	int id;
}peo[50005];
struct Node{
	int l;
	int r;
	int w;
}tree[50005*4];
int Loy[1000005];
vector<int> line[50005];
int tot;
int l[50005],r[50005];
int cmp(node a,node b){
	if(a.abi==b.abi){
		return a.id<b.id;
	} 
	else{
		return a.abi>b.abi;
	}
}
int dfs(int x){
	l[x]=tot++;
	for(int i=0;i<line[x].size();i++){
		dfs(line[x][i]);
	}
	r[x]=tot;
}
void build(int s,int t,int k){
	tree[k].l=s;
	tree[k].r=t;
	tree[k].w=-1;
	if(s==t){
		return ;
	}
	int m=(s+t)/2;
	build(s,m,2*k);
	build(m+1,t,2*k+1);
}
void insert(int s,int t,int k,int w){
	if(tree[k].l==s&&tree[k].r==t){
		tree[k].w=w;
		return ;
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(t<=m){
		insert(s,t,2*k,w);
	}else if(s>m){
		insert(s,t,2*k+1,w);
	}
	tree[k].w=max(tree[2*k].w,tree[k*2+1].w);
}
int query(int s,int t,int k){
	if(s>t){
		return -1;
	}if(tree[k].l==s&&tree[k].r==t){
		return tree[k].w;
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(t<=m){
		return query(s,t,2*k);
	}else if(s>m){
		return query(s,t,2*k+1);
	}else{
		return max(query(s,m,2*k),query(m+1,t,2*k+1));
	}
}
int ans[50005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			line[i].clear();
		}
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&peo[i].pre,&peo[i].loy,&peo[i].abi);
			peo[i].id=i;
			Loy[peo[i].loy]=i;
			line[peo[i].pre].push_back(i);
		}
		tot=1;
		dfs(0);
		build(1,tot-1,1);
		sort(peo+1,peo+n,cmp);
//		for(int i=1;i<n;i++)
//        {
//            printf("%d:%d %d% d\n",i,peo[i].id,peo[i].loy,peo[i].abi);
//            printf("%d %d\n",l[peo[i].id],r[peo[i].id]);
//        }
		int num=1;
		while(num<n){
			int now=num;
			while(now<n&&peo[num].abi==peo[now].abi){
				int temp;
				temp=query(l[peo[now].id]+1,r[peo[now].id]-1,1);
				if(temp==-1){
					ans[peo[now].id]=-1;
				}else{
					ans[peo[now].id]=Loy[temp];
				}
				now++;
			}
			now=num;
			while(now<n&&peo[num].abi==peo[now].abi){
				insert(l[peo[now].id],l[peo[now].id],1,peo[now].loy);
				now++;
			}
			num=now;
		}
		while(m--){
			int q;
			scanf("%d",&q);
			printf("%d\n",ans[q]);
		}
	}
	return 0;
} 
