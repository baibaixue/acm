#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1005
#define inf 0x3f3f3f3f
using namespace std;
int N[maxn];
struct node{
	int l,r;
	int c;
}edge[20005];
int cmp(node a,node b){
	return a.c>b.c;
}
int find(int r){
	while(r!=N[r]){
		r=N[r];
	}
	return r;
}
bool hebing(int a,int b){
	int x=find(a);
	int y=find(b);
	while(x!=y){
		N[y]=x;
		return true;
	}
	return false;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			N[i]=i;
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&edge[i].l,&edge[i].r,&edge[i].c);
		}
		sort(edge+1,edge+m+1,cmp);
		int ans=0;
		for(int i=1;i<=m;i++){
			if(hebing(edge[i].l,edge[i].r)==true){
				ans+=edge[i].c;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(N[i]==i){
				cnt++;
			}
		}
		if(cnt>1){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}

