#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct t{
	int ti_s,ti_e;
}n[120];
int cmp(t a,t b){
	return a.ti_e<b.ti_e;
} 
int main(){
	int N;
	while(scanf("%d",&N)!=EOF&&N){
		for(int i=0;i<N;i++){
			scanf("%d%d",&n[i].ti_s,&n[i].ti_e);
		}
		sort(n,n+N,cmp);
		int ans=1;
		int a=n[0].ti_e; 
		for(int i=1;i<N;i++){
			if(n[i].ti_s>=a){
				ans++;
				a=n[i].ti_e;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
