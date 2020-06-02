#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int l;
	int r;
	long long c;
	int f;
}tree[400000];
long long ans;
int L,T,O;
void build(int s,int t,int k){
	tree[k].l=s;
	tree[k].r=t;
	tree[k].c=1;
	tree[k].f=0;
	if(s==t){
		return ;
	}
	int m=(s+t)/2;
	build(s,m,2*k);
	build(m+1,t,2*k+1);
}
void down(int k){
	tree[k*2].f=tree[k].f;
	tree[k*2+1].f=tree[k].f;
	tree[k*2].c=1<<(tree[k].f-1);
	tree[k*2+1].c=1<<(tree[k].f-1);
	tree[k].f=0;
}
void change(int s,int t,int c,int k){
	if(tree[k].l>=s&&tree[k].r<=t){
		tree[k].c=1<<(c-1);
		tree[k].f=c;
		return ;
	}
	if(tree[k].f){
		down(k);
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(s<=m){
		change(s,t,c,k*2);
	}
	if(t>m){
		change(s,t,c,k*2+1);
	}
	tree[k].c=tree[2*k].c|tree[2*k+1].c;
}
void query(int s,int t,int k){
	if(tree[k].l>=s&&tree[k].r<=t){
		ans=ans|tree[k].c;
		return ;
	}
	if(tree[k].f){
		down(k);
	}
	int m=(tree[k].l+tree[k].r)/2;
	if(s<=m){
		query(s,t,k*2);
	}
	if(t>m){
		query(s,t,k*2+1);
	}
}
int count(long long x){
	int cnt=0;
	for(int i=0;i<=T;i++){
		if((x&(1<<i))!=0){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	while(scanf("%d%d%d",&L,&T,&O)!=EOF){
		build(1,L,1);
		for(int i=0;i<O;i++){
			char c;
			int a,b,d;
			getchar();
			scanf("%c",&c);
			if(c=='C'){
				scanf("%d%d%d",&a,&b,&d);
				int A=min(a,b);
				int B=max(a,b);
				change(A,B,d,1);
			}
			if(c=='P'){
				scanf("%d%d",&a,&b);
				int A=min(a,b);
				int B=max(a,b);
				ans=0;
				query(A,B,1);
				printf("%d\n",count(ans));
			}
		}
	}
	return 0;
}
