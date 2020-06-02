#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 500010
using namespace std;
int tree[maxn][26];
int tot;
void in_sert(char *str){
	int root=0;
	int len=strlen(str);
	for(int i=0;i<len;i++){
		int id=str[i]-'a';
		if(tree[root][id]==-1){
			tree[root][id]=++tot;
		}
		root=tree[root][id];
	}
	return ;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		tot=0;
		for(int i=0;i<maxn;i++){
			for(int j=0;j<26;j++){
				tree[i][j]=-1;
			}
		}
		getchar();
		int m=0;
		int len;
		char word[55];
		for(int i=0;i<n;i++){
			gets(word);
			len=strlen(word);
			if(m<len){
				m=len;
			}
			in_sert(word);
			memset(word,0,sizeof(word));
		}
		int res=0;
		res=tot*2+n-m;
		printf("%d\n",res);
	}
	return 0;
}
