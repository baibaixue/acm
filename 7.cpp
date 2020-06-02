#include<stdio.h>//qw的表白//2018新生杯 
#include<math.h>
#include<algorithm>
#define maxn 50050
using namespace std;
long long int a[maxn];
int lower_search(long long int* a,int x,int y,double v){
	int m;
	while(y>x){
		m=x+(y-x)/2;
		if(a[m]>=v){
			y=m;
		}else{
			x=m+1;
		}
		if(a[m]<v&&a[m+1]>=v){
			return m+1;
		}
	}
}
int upper_search(long long int* a,int x,int y,double v){
	int m;
	while(y>x){
		m=x+(y-x)/2;
		if(a[m]<=v){
			x=m+1;
		}else{
			y=m;
		}
		if(a[m]<=v&&a[m+1]>v){
			return m;
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		while(m--){
			double l,r;
			scanf("%lf%lf",&l,&r);
			l=sqrt(l);
			r=sqrt(r);
			int x,y;
			int s=0,e=n;
			x=lower_search(a,s,e,l);
			if(r>=a[n-1]){
				y=n-1;
			}else{
				y=upper_search(a,s,e,r);
			}
			printf("%d\n",y-x+1);
		}
	}
	return 0;
}
