#include<stdio.h>//激烈的决斗者//2018新生杯 
#include<algorithm>
using namespace std;
#define max 550
struct x{
	long long int ai,bi,c;
}num[500];
int cmp(x a,x b){
	return a.c>b.c;
}
int main(){
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%lld%lld",&num[i].ai ,&num[i].bi);
			num[i].c=num[i].bi-num[i].ai;
		}
		sort(num,num+n,cmp);
		long long int comp;
		for(int i=0;i<m;i++){
			comp=num[i].ai;
			num[i].ai=num[i].bi;
			num[i].bi=comp;
			if(num[i].c<=0){
				break;
			}
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			ans+=num[i].ai;
		}
		printf("%lld",ans);
	}
	return 0;
}
