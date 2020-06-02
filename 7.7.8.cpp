#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define maxn 350
#define inf 0x3f3f3f3f3f
using namespace std;
long long r[maxn][maxn];
struct road{
	long long p;
	int s,e;
};
vector<int> link[maxn];
road edge[maxn*maxn];
bool cmp(road a,road b){
	return a.p<b.p;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(r,inf,sizeof(r));
		for(int i=0;i<=n;i++){
			link[i].clear();
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			long long p;
			for(int k=1;k<=i;k++){
				scanf("%lld",&p);
			}
			for(int j=i+1;j<=n;j++){
				scanf ("%lld",&p);
					edge[cnt].p=p;
					edge[cnt].s=i;
					edge[cnt].e=j;
					cnt++;
			}
		}
		sort(edge,edge+cnt,cmp);
		int ans=0;
		for(int i=0;i<cnt;i++){
			if(r[edge[i].s][edge[i].e]>edge[i].p){
				ans++;
				r[edge[i].s][edge[i].e]=edge[i].p;
				r[edge[i].e][edge[i].s]=edge[i].p;
				for(int j=0;j<link[edge[i].s].size();j++){
					r[edge[i].e][link[edge[i].s][j]]=min(r[edge[i].e][link[edge[i].s][j]],r[edge[i].s][link[edge[i].s][j]]+edge[i].p);
					r[link[edge[i].s][j]][edge[i].e]=r[edge[i].e][link[edge[i].s][j]];
				}
				link[edge[i].s].push_back(edge[i].e);
				link[edge[i].e].push_back(edge[i].s);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//5
//0 2 3 5 2
//2 0 3 4 2
//3 3 0 4 2
//2 2 2 0 7
//2 2 2 7 0
