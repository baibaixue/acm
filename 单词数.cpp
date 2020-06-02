#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 100005
using namespace std;
int tree[maxn][30];
int code[maxn];
int tot;
int in_sert(char *str){
	int ans=0;
	int len=strlen(str);
	int root=0;
	for(int i=0;i<len;i++){
		int id=str[i]-'a'+1;
		if(str[i]==' '){
			id=0;
		}
		if(tree[root][id]==0){
			tree[root][id]=++tot;
		}
		root=tree[root][id];
		if(str[i]==' '){
			if(code[root]==0){
				if(root!=1&&str[i-1]!=' ')
				ans++;
				code[root]=1;
			}
			root=0;
		}
	}
	return ans;
}
int main(){
	char word[maxn];
	memset(word,0,sizeof(word));
	while(cin.getline(word,maxn)){		
		if(word[0]=='#'){
			break;
		}
		memset(code,0,sizeof(code));
		memset(tree,0,sizeof(tree));
		tot=0;
		int len=strlen(word);
		word[len]=' ';
		int ans=in_sert(word);
		printf("%d\n",ans);
		memset(word,0,sizeof(word));
	}
	return 0;
}
