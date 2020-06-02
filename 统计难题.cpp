#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
const int maxn=2e6+5;
using namespace std;
int tree[maxn][30];
int code[maxn];
int tot;
int sum[maxn];
void in_sert(char *str){
	int len=strlen(str);
	int root=0;
	for(int i=0;i<len;i++){
		int id=str[i]-'a';
		if(tree[root][id]==0){
			tree[root][id]=++tot;
		}
		sum[tree[root][id]]++;
		root=tree[root][id];
	}
	code[root]=1;
}
int my_search(char *str){
	int len=strlen(str);
	int root=0;
	for(int i=0;i<len;i++){
		int id=str[i]-'a';
		if(tree[root][id]==0){
			return 0;
		}
			root=tree[root][id];
		}
	return sum[root];
}
int main(){
	char word[15];
	memset(sum,0,sizeof(sum));
	while(gets(word)){
		in_sert(word);
		if(word[0]=='\0'){
			break;
		}
		memset(word,0,sizeof(word));
	}
	char q[15];
	while(scanf("%s",q)!=EOF){
		int ans=my_search(q);
		printf("%d\n",ans);
	}
	return 0;
}
