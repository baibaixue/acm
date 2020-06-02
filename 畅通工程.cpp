#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1010
using namespace std;
int road[maxn];
int find(int x){
	int r=x;
	while(road[r]!=r){
		r=road[r];
	}
	return r;
}
void merge(int x,int y){
	int a=find(x);
	int b=find(y);
	int A=min(a,b);
	int B=max(a,b);
	if(A!=B){
		road[B]=A;
	//	printf("road[%d]=%d,road[%d]=%d,road[%d]=%d\n",x,road[x],y,road[y],b,road[b]);
	}
}
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&m);
		for(int i=0;i<maxn;i++){
			road[i]=i;
		}
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			int x=min(a,b);
			int y=max(a,b);
			merge(x,y);
		}
		int count=0;
		int ans[maxn];
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			if(find(i)!=0){
				ans[count]=i;
				count++;
			}
		}
		printf("%d\n",count);
		if(count==0){
		}else{
			for(int i=0;i<count-1;i++){
				printf("%d ",ans[i]);
			}
			printf("%d\n",ans[count-1]);
		}
		
	}
	return 0;
}
