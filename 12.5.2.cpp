#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int dian[1005];
int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		memset(dian,0,sizeof(dian));
		for(int i=0;i<t;i++){
			int n;
			scanf("%d",&n);
			for(int j=0;j<n;j++){
				int a;
				scanf("%d",&a);
				dian[a]++;
			}
		}
		int maxn=dian[1000],x=1000;
		for(int i=1000;i>=1;i--){
			if(dian[i]>maxn){
				maxn=dian[i];
				x=i;
			}
		}
		printf("%d %d\n",x,dian[x]);
	}
	return 0;
}
