#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath> 
#define maxn 2005
#define inf 0x3f3f3f3f
using namespace std;
struct node{
	long long l,r;
}line[maxn];
int n,m;
void move_left(int x,long long k){
	line[x].l-=k;
	line[x].r-=k;
	if(x==1){
		return ;
	}else{
		if(line[x-1].r>line[x].l){
			move_left(x-1,line[x-1].r-line[x].l);
		}else{
			return ;
		}
	}
}
void move_right(int x,long long k){
	line[x].l+=k;
	line[x].r+=k;
	if(x==n){
		return ;
	}else{
		if(line[x+1].l<line[x].r){
			move_right(x+1,line[x].r-line[x+1].l);
		}else{
			return ;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&line[i].l,&line[i].r);
		}
		for(int i=0;i<m;i++){
			getchar();
			char c;
			scanf("%c",&c);
			if(c=='?'){
				int x;
				scanf("%d",&x);
				printf("%lld\n",line[x].l);
			}else if(c=='L'){
				int x;
				long long k;
				scanf("%d%lld",&x,&k);
				move_left(x,k);
			}else if(c=='R'){
				int x;
				long long k;
				scanf("%d%lld",&x,&k);
				move_right(x,k);
			}
		}
	} 
}
