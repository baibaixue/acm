#include<cstdio>
#include<string.h>
#define maxn 505
using namespace std;
int city[maxn];
int lost[maxn];
struct road{
	int s;int e;
}l[5005];
int find(int x){
	int r=x;
	if(r!=city[r]){
		r=find(city[r]);
	}
	return r;
}
int hebing(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		city[b]=a;
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			city[i]=i;
			lost[i]=1;
		}
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			l[i].s=a;
			l[i].e=b;
			hebing(a,b);
		}
		int countr=0;
		for(int i=0;i<n;i++){
			if(city[i]==i){
				countr++;
			}
		}
		int k;
		scanf("%d",&k);
		int tt=k;
		while(k--){
			int lost_city;
			scanf("%d",&lost_city);
			lost[lost_city]=0;
		for(int i=0;i<n;i++){
			city[i]=i;
		}
		int counte=0;
			for(int i=0;i<m;i++){
				if(lost[l[i].s]==1&&lost[l[i].e]==1){
					hebing(l[i].s,l[i].e);
				}
			}
			for(int i=0;i<n;i++){
				if(city[i]==i){
				counte++;
			} 
		}
			if(countr==counte||countr==counte-1){
				printf("City %d is lost.\n",lost_city);
			}else{
				printf("Red Alert: City %d is lost!\n",lost_city);
			}
			countr=counte;
		}
		if(tt==n){
				printf("Game Over.\n");
			}
	}
	return 0;
}
