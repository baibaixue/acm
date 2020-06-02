#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10005
using namespace std;
struct node{
	int a,b,g,k;
}num[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&num[i].a,&num[i].b,&num[i].g,&num[i].k);
		num[i].g+=num[i].a;
		num[i].k+=num[i].b;
	}
	int x,y;
	scanf("%d%d",&x,&y);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(num[i].a<=x&&num[i].b<=y&&num[i].g>=x&&num[i].k>=y){
			ans=i;
		}
	}
	if(ans==0){
		printf("-1\n");
	}else{
		printf("%d\n",ans);
	}
	return 0;
}
