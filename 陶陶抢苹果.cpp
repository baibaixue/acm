#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxn 100005
using namespace std;
struct Tao{
	int id;
	int w;
	int a;
}tao[maxn];
int apple[maxn];
int cmp1(int a,int b){
	return a>b;
}
int cmp2(Tao x,Tao y){
	return x.w>y.w;
}
int cmp3(Tao x,Tao y){
	return x.id<y.id;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<maxn;i++){
			tao[i].id=0;
			tao[i].w=0;
			tao[i].a=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&apple[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&tao[i].w);
			tao[i].id=i;
		}
		sort(apple+1,apple+n+1,cmp1);
		sort(tao+1,tao+m+1,cmp2);
		for(int i=1;i<=n;i++){
			int t=i%m;
			if(t==0){
				t=m;
			}
			tao[t].a+=apple[i];
		}
		sort(tao+1,tao+m+1,cmp3);
		for(int i=1;i<m;i++){
			printf("%d ",tao[i].a);
		}
		printf("%d\n",tao[m].a);
	}
	return 0;
}
