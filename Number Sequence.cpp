#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string.h>
#include<string>
using namespace std;
string s;
string subs;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		getchar();
		getline(cin,s,'\n');
		getline(cin,subs,'\n');
		int ans=s.find(subs);
		if(ans==-1){
			printf("-1\n");
		}else{
			printf("%d\n",ans/2+1);
		}
	}
} 
