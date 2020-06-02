#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 50005
using namespace std;
int A[maxn];
int main(){
	int n,q;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&A[i]);
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int x;
			scanf("%d",&x);
			if(x==2){
				int y;
				scanf("%d",&y);
				printf("%d\n",A[y]);
			}
			if(x==1){
				int a,b,k,c;
				scanf("%d%d%d%d",&a,&b,&k,&c);
				for(int i=a;i<=b;i+=k){
					if((i-a)%k==0){
						A[i]+=c;
					}
				}
			}
		}
	}
	return 0;
} 
