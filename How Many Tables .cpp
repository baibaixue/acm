#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 1010
using namespace std;
int num[maxn];
int find(int x){
	int r=x;
	while(r!=num[r]){
		r=num[r];
	}
	return r;
}
void hebing(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		num[b]=a;
		//printf("num[%d]=%d,num[%d]=%d,num[%d]=%d\n",b,num[b],y,num[y],x,num[x]);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++){
			num[i]=i;
		}
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			hebing(a,b);
		}
		int count=0;
		for(int i=1;i<=n;i++){
			if(num[i]==i){
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
} 
