//最小生成树问题 
/*
8 14
a b 4
a c 3
c b 5
c d 5
c h 5
b d 5
b e 9
d e 7
d h 4
d g 5
d f 6
h g 6
g f 2
f e 3
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 105
using namespace std;
struct cost{
	char s; //起点 
	char e; //终点 
	int m; //权值 
}road[maxn*maxn];//边信息 
int v[maxn]; //顶点信息 
int find(int x){
	int r=x;
	if(r==v[r]){
		return x;
	}else{
		return find(v[r]);
	}
}
void merge(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		v[b]=a;
	}
}
int cmp(cost a,cost b){
	return a.m<b.m;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
		for(int i=0;i<=n;i++){
			v[i]=i;
		}
		for(int i=0;i<m;i++){
			getchar();
			scanf("%c %c %d",&road[i].s,&road[i].e,&road[i].m);
		}
		sort(road,road+m,cmp);
		int ans=0;
		for(int i=0;i<m;i++){
			if(find((int)(road[i].s-'a'))!=find((int)(road[i].e-'a'))){
				ans+=road[i].m;
				merge((int)(road[i].s-'a'),(int)(road[i].e-'a'));
				printf("%c %c val:%d\n",road[i].s,road[i].e,road[i].m);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
