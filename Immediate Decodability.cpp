#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 100
using namespace std;
int tree[maxn][2];
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
	char c[15];
	int a;
	int t=1;
	while(scanf("%s",c)!=EOF){
		memset(tree,0,sizeof(tree));
		for(int i=0;i<maxn;i++){
			code[i]=false;
		}
		
		int ans=1;
		
		tot=0;
		a=in_sert(c);
		getchar();
		while(scanf("%s",c)!=EOF&&c[0]!='9'){
			a=in_sert(c);
			if(a==0){
				ans=0;
			}
			getchar();
		}
		if(ans==1){
			printf("Set %d is immediately decodable\n",t);
		}else{
			printf("Set %d is not immediately decodable\n",t);
		}
		t++;
	}
	return 0;
}

 
