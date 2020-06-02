#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1005
#define inf 0x3f3f3f3f 
using namespace std;
int p[maxn];
int c[maxn];
int d[maxn];
int cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(p,0,sizeof(p));
		memset(c,0,sizeof(c));
		
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		int Max=inf;
		Max*=(-1);
		int sum,num=0;
		for(int k=1;k<=n;k++){
			memset(d,0,sizeof(d));
			sum=0;
			for(int i=1;i<=n;i++){
				d[i]=p[i]-(k-1)*c[i];
			}
			sort(d+1,d+n+1,cmp);
			for(int j=1;j<=k;j++){
				sum+=d[j];
			}
			if(sum>=Max){
				Max=sum;
				num=k;
			}
		}
		printf("%d\n%d\n",Max,num);
	}
	return 0;
} 
