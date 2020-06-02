#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#define maxn 100005
using namespace std;
map<long long,vector<int> > M;
long long t[maxn];
long long A[maxn];
int num[maxn];
string s[maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		M.clear();
		getchar();
		for(int i=1;i<=n;i++){
			scanf("%lld",&A[i]);
			M[A[i]].push_back(i);
		}
		scanf("%lld",&t[0]);
		int cnt=1;
		int pos=0;
		int is_false=0;
		if(M[t[0]].empty()){
			is_false=1;
			cnt=-1; 
		}else{
			pos=M[t[0]].front();
		}
		for(int i=1;i<m;i++){
			scanf("%lld",&t[i]);
			if(M[t[i]].empty()){
				is_false=1; 
				cnt=-1;
			}
			if(is_false==0){
				int is_ok=0;
				for(int j=0;j<M[t[i]].size();j++){
					if(pos<M[t[i]][j]){
						pos=M[t[i]][j];
						is_ok=1;
						break;
					}
				}
				if(is_ok==0){
					pos=M[t[i]].front();
					cnt++;
				}
			}
			
		}
		printf("%d\n",cnt);
	}
}
