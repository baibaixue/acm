#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define maxn 20005
using namespace std;
struct node{
	int v;
	int x;
}cow[maxn];
int lowbit(int i){
	return i&(-i);
}
int cmp(node a,node b){
	return a.v<b.v;
}
int anum[maxn];
int bnum[maxn];
void add(int* num,int x,int c){
	while(x<maxn){
		num[x]+=c;
		x+=lowbit(x);
	}
}
int sum(int *num,int x){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		sum+=num[i];
	}
	return sum;
} 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(anum,0,sizeof(anum));
		memset(bnum,0,sizeof(bnum));
		for(int i=1;i<=n;i++){
			scanf("%d%d",&cow[i].v,&cow[i].x);
		}
		sort(cow+1,cow+n+1,cmp);
		long long ans=0;
		int total=0;
		for(int i=1;i<=n;i++){
			int t=cow[i].x;
			total+=t;
			add(anum,t,1);
			add(bnum,t,t);
			int t1=sum(anum,t);
			int t2=sum(bnum,t);
			int cnt1=t1*t-t2;
			int cnt2=total-t2-t*(i-t1);
			ans+=((long long)cnt1+cnt2)*cow[i].v;
		}
		printf("%lld\n",ans);
	} 
}

