//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<string.h>
//#define maxn 50005
//using namespace std;
//struct node{
//	int id,abi,loy,pre;
//}tree[maxn];
//node peo[maxn];
//bool cmp(node a,node b){
//	return a.id<b.id;
//}
//int main(){
//	int t;
//	scanf("%d",&t);
//	while(t--){
//		int n,m;
//		for(int i=0;i<maxn;i++){
//			tree[i].id=0;tree[i].abi=0;tree[i].loy=0;
//			peo[i].id=0;peo[i].abi=0;peo[i].loy=0;
//		}
//		scanf("%d%d",&n,&m);
//		for(int i=1;i<n;i++){
//			int a,b,c;
//			scanf("%d%d%d",&a,&b,&c);
//			peo[i].id=i;peo[i].abi=c;peo[i].loy=b;peo[i].pre=a;
//		}
//		sort(tree+1,tree+1+n,cmp);
//		for(int i=1;i<n;i++){
//			int a=peo[i].pre;
//			if(peo[a].abi<peo[i].abi&&peo[i].loy>=tree[a].loy){
//				tree[a].id=peo[i].id;
//				tree[a].abi=peo[i].abi;
//				tree[a].loy=peo[i].loy;
//			}
//		}
//		for(int i=0;i<m;i++){
//			int q;
//			scanf("%d",&q);
//			if(tree[q].id==0){
//				printf("-1\n");
//			}else{
//				printf("%d\n",tree[q].id);
//			}
//		}
//	}
//	return 0;
//}
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
 
const int maxn=5e4+10;
const int maxm=1e6+10;
struct node{
    int num,ability,loyalty;
}f[maxn];
struct tree{
    int l,r,maxv;
}e[maxn*4];
int ha[maxm],l[maxn],r[maxn],t,ans[maxn];
vector<int>mm[maxn];
void dfs(int x)
{
    l[x]=t++;
    for(int i=0;i<mm[x].size();i++)
    {
        dfs(mm[x][i]);
    }
    r[x]=t;
}
int cmp(node a,node b)
{
    if(a.ability==b.ability)return a.num<b.num;
    return a.ability>b.ability;
}
void build(int a,int b,int c)
{
    e[c].l=a;
    e[c].r=b;
    e[c].maxv=-1;
    if(a==b)return ;
    int mid=(a+b)/2;
    build(a,mid,2*c);
    build(mid+1,b,2*c+1);
}
void update(int a,int b,int c,int val)
{
    if(e[c].l==a&&e[c].r==b)
    {
        e[c].maxv=val;
        return ;
    }
    int mid=(e[c].l+e[c].r)/2;
    if(b<=mid)update(a,b,2*c,val);
    else if(a>mid)update(a,b,2*c+1,val);
    e[c].maxv=max(e[2*c].maxv,e[2*c+1].maxv);
}
int query(int a,int b,int c)
{
    if(a>b)return -1;
    if(e[c].l==a&&e[c].r==b)return e[c].maxv;
    int mid=(e[c].l+e[c].r)/2;
    if(b<=mid)return query(a,b,2*c);
    else if(a>mid)return query(a,b,2*c+1);
    else return max(query(a,mid,2*c),query(mid+1,b,2*c+1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n,m,pre;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)mm[i].clear();
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&pre,&f[i].loyalty,&f[i].ability);
            mm[pre].push_back(i);
            f[i].num=i;
            ha[f[i].loyalty]=i;
        }
        t=1;
        dfs(0);
        build(1,t-1,1);
        sort(f+1,f+n,cmp);
        for(i=1;i<n;i++)
        {
            printf("%d:%d %d% d\n",i,f[i].num,f[i].loyalty,f[i].ability);
            printf("%d %d\n",l[f[i].num],r[f[i].num]);
        }
        i=1;
        while(i<n)
        {
            j=i;
            while(j<n&&f[i].ability==f[j].ability)
            {
                k=query(l[f[j].num]+1,r[f[j].num]-1,1);
                if(k==-1)ans[f[j].num]=-1;
                else ans[f[j].num]=ha[k];
                j++;
            }
            j=i;
            while(j<n&&f[i].ability==f[j].ability)
            {
                update(l[f[j].num],l[f[j].num],1,f[j].loyalty);
                j++;
            }
            i=j;
        }
        while(m--)
        {
            scanf("%d",&k);
            printf("%d\n",ans[k]);
        }
    }
    return 0;
}
