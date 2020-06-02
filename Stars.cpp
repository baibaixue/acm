#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn  32005
using namespace std;
int a[maxn];int b[maxn];
int n;
int lowbit(int x){
	return x&(-x);
}
void add(int i){
	while(i<=maxn){
		b[i]+=1;
		i+=lowbit(i);
	}
}
int quest(int i){
	int res=0;
	while(i>0){
		res+=b[i];
		i-=lowbit(i);
	}
	return res;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x++;
			a[quest(x)]++;
			add(x);
		}
		for(int i=0;i<n;i++){
			printf("%d\n",a[i]);
		} 
	}
	return 0; 
}

