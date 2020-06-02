#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct jew{
	int v,vail;
}va[1020];
int cmp(jew a,jew b){
	return a.p>b.p;
}
int ans[1010][2020];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int N,V;
		scanf("%d%d",&N,&V);
		for(int i=1;i<=N;i++){
			scanf("%d",&va[i].vail);
			va[i].v=i;
		}
		for(int i=1;i<N;i++){
			
		}
		
	}
}
