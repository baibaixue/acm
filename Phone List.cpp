#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
const int maxn=100005;
using namespace std;
int tree[maxn][15];
bool code[maxn];
int tot;
bool in_sert(char *str){
	int len=strlen(str);
	int root=0;
	int ok=0;
	for(int i=0;i<len;i++){
		int id=str[i]-'0';
		if(code[root]==1){
			return false;
		}
		if(tree[root][id]==0){
			ok=1;
			tree[root][id]=++tot;
		}
		root=tree[root][id];
	}
	code[root]=true;
	if(ok==1){
		return true;
	}else{
		return false;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		char c[15];
		int a;
		int ans=1;
		tot=0;
		memset(tree,0,sizeof(tree));
		for(int i=0;i<maxn;i++){
				code[i]=false;
			}
		getchar();
		for(int i=0;i<n;i++){
			scanf("%s",c);
			a=in_sert(c);
			if(a==0){
				ans=0;
			}
			getchar();
		}
			if(ans==1){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
	}
	return 0;
}

