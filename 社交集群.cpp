#include<cstdio>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define maxn 10010
using namespace std;
int N[maxn];
int sum[maxn];
int h[maxn];
int find(int a){
	a=N[a];
	while(a!=N[a]){
		a=N[a];
	}
	return a;
}
void hebing(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y){
		N[y]=x;
	}
	
}
int cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int k;
		for(int i=0;i<=n;i++){
			N[i]=i;
		}
		memset(h,0,sizeof(h));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			scanf("%d:",&k);
			for(int j=1;j<=k;j++){
				int a;
				scanf("%d",&a);
				if(h[a]==0){
					h[a]=i;
				}else{
					hebing(h[a],i);
					h[a]=i;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(find(i)==i){
				cnt++;
			}
			sum[find(i)]++;
		}
		printf("%d\n",cnt);
		sort(sum,sum+maxn,cmp);
		for(int i=0;i<cnt-1;i++){
			printf("%d ",sum[i]);
		}
		printf("%d\n",sum[cnt-1]);
	}
	return 0;
}
