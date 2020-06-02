#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#define maxn 15
using namespace std;
int n,k,a[maxn],visit[maxn];
int ans;
int judge(int x,int y){
	if(fabs(x-y)<=k){
		return 1;
	}else{
		return 0;
	}
}
void dfs(int last,int m){
	if(m==n){
		if(judge(last,a[1])){
			ans++;
			return ;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(visit[i]!=1&&judge(last,a[i])){
				visit[i]=1;
				dfs(a[i],m+1);
				visit[i]=0;
			}
		}
	}
	return ;
}
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		ans=0;
		memset(a,0,sizeof(a));
		memset(visit,0,sizeof(visit));
		visit[1]=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dfs(a[1],1);
		printf("%d\n",ans);
	}
}
