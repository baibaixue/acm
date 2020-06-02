#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#define inf 0f3x3x3x3x
#define maxn 10005
using namespace std;
map<string,int> M;
int t[maxn];
string s[maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		getchar();
		for(int i=1;i<=n;i++){
			cin>>s[i];
			M[s[i]]=i;
		}
		for(int i=0;i<m;i++){
			string str;
			cin>>str;
			t[i]=M[str];
			//printf("%d ",t[i]);
		}
		int cnt=1;
		for(int i=0;i<m-1;i++){
			if(t[i]>=t[i+1]){
				cnt++;
			}if(t[i]==0){
				cnt=-1;
				break;
			}
		}
		if(t[m-1]==0){
			cnt=-1;
		}
		printf("%d\n",cnt);
	}
}
