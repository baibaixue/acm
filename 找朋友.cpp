#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#define maxn 2000005
using namespace std;
string child[maxn];
long long N[maxn];
int cmp1(string a,string b){
	return a<b;
}
int cmp2(long long a,long long b){
	return a<b;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			cin>>child[i];
		}
		for(int i=1;i<=n;i++){
			cin>>N[i];
		}
		sort(child+1,child+n+1,cmp1);
		sort(N+1,N+n+1,cmp2);
		for(int i=1;i<=n;i++){
			cout<<child[i]<<" "<<N[i]<<endl;
		}
	}
	return 0;
}
