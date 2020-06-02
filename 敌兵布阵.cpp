#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#define maxn 50005
int a[maxn];
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		a[0]=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			a[i]=a[i-1]+x;
		}
		printf("Case %d:\n",t);
		char q[10];
		while(scanf("%s",q)&&q[0]!='E'){
			int i,j;
			if(q[0]=='Q'){
				scanf("%d%d",&i,&j);
				printf("%d\n",a[j]-a[i-1]);
			}if(q[0]=='A'){
				scanf("%d%d",&i,&j);
				for(int l=i;l<=n;l++){
					a[l]+=j;
				}
			}if(q[0]=='S'){
				scanf("%d%d",&i,&j);
				for(int l=i;l<=n;l++){
					a[l]-=j;
				}
			}
		}
	}
	return 0;
} 
