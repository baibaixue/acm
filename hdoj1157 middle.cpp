#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 10000+50
using namespace std;
int m[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			cin>>m[i];
		}
		sort(m,m+n);
		cout<<m[n/2]<<"\n";
	}
	return 0;
	
}
