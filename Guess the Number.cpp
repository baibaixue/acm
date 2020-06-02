#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#define maxn 100005
#define inf (1e9+5)
using namespace std;
struct node{
	int id;
	long long price;
};
struct edge{
	int to;
	long long price;
};
vector<edge> link[maxn];
node p[maxn];
long long ans[maxn];
bool cmp(node a,node b){
	return a.price<b.price;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			link[i].clear();
			long long pi;
			scanf("%lld",&pi);
			p[i].id=i; 
			p[i].price=pi;
			ans[i]=pi;
		}
		for(int i=0;i<m;i++){
			int a,b;
			long long c;
			edge temp1;
			scanf("%d%d%lld",&a,&b,&c);
			temp1.to=b;
			temp1.price=c;
			link[a].push_back(temp1);
			edge temp2;
			temp2.to=a;
			temp2.price=c;
			link[b].push_back(temp2);
		}
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<link[p[i].id].size();j++){
				ans[link[p[i].id][j].to]=min(ans[link[p[i].id][j].to],link[p[i].id][j].price);
			}
		}
		long long res=0;
		for(int i=1;i<=n;i++){
			res+=ans[i];
		}
		printf("%lld\n",res);
	}
}



