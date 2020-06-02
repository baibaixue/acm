#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 500005
using namespace std;
int tree[maxn][30];
bool flag[maxn];
int tot;
char word[50005][65];
void build(char* s){
	int root=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		int id=s[i]-'a';
		if(tree[root][id]==0){
			tree[root][id]=++tot;
		}
		root=tree[root][id];
	}
	flag[root]=true;
}
bool query(char* s){
	int root=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		int id=s[i]-'a';
		if(tree[root][id]!=0){
			root=tree[root][id];
			if(flag[root]==true){
				int Root=0;
				for(int j=i+1;j<len;j++){
					id=s[j]-'a';
					if(tree[Root][id]!=0){
						Root=tree[Root][id];
						if(flag[Root]==true&&j==len-1){
							return true;
						}
					}else{
						break;
					}
				}
			}
		}
	}
	return false;
}
int main(){
	//memset(tree,0,sizeof(tree));
	//memset(flag,false,sizeof(flag));
	//memset(word,0,sizeof(word));
	tot=0;
	int num=0;
	while(scanf("%s",word[num++])!=EOF){
		build(word[num-1]);
	}
	for(int i=0;i<num;i++){
		if(query(word[i])==true){
			printf("%s\n",word[i]);
		}
	}
	return 0;
}
 
