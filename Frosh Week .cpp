#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1000005
using namespace std;
struct node{
	long long val;
	int order;
}a[maxn];
int b[maxn];
int c[maxn];
int n;
int cmp(node a,node b){
	return a.val<b.val;
}
int lowbit(int x){
	return x&-x;
}
void add(int i){
	while(i<=n){
		c[i]+=1;
		i+=lowbit(i);
	}
}
long long quest(int i){
	long long res=0;
	while(i>0){
		res+=c[i];
		i-=lowbit(i);
	}
	return res;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i].val);
			a[i].order=i;
		}
		sort(a+1,a+n+1,cmp);
		long long sum=0;
		for(int i=1;i<=n;i++){
			b[a[i].order]=i;
			//printf("b[%d]=%d\n",a[i].order,i);
		}
		for(int i=1;i<=n;i++){
			add(b[i]);
			sum+=(i-quest(b[i]));
		}
		printf("%lld\n",sum);
	}
	return 0;
} 
