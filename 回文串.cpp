#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 1000006
using namespace std;
int a[maxn];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
		int ans=0;
		for(int i=n/2;i<n;i++){
			ans+=a[i]-a[n/2];
		}
		printf("%d\n",ans);
	}
	return 0;
} 
