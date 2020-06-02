#include<cstdio>///////未能处理字符对应仅为前缀 的情况 
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn  3050
using namespace std;
int tree[500005][100];
int flag[500005];
char code[500005][15];
int tot;
void in_sert(char *str1,char *str2){
	int len=strlen(str2);
	int root=0;
	for(int i=0;i<len;i++){
		int id=str2[i]-' ';
		if(tree[root][id]==0){
			tree[root][id]=++tot;
		}
		root=tree[root][id];
	}
	flag[root]=1;
	strcpy(code[root],str1);
	return ;
}
void Print(char *str){
	int len=strlen(str);
	int root=0;
	int a,b,ok=0;
	for(int i=0;i<len;i++){
		int id=str[i]-' ';
//		if(id<0||id>=26){
//			printf("%c",str[i]);
//		}
		if(tree[root][id]==0){
			printf("%c",str[i]);
			if(ok==0){
				a=i;
			}
			if(ok==1)
			for(int j=a;j<b;j++){
				printf("%c",str[j]);
				ok=0;
			}
		}
		root=tree[root][id];
		if(flag[root]==1&&(str[i+1]<'a'||str[i+1]>'z')){
			b=i;
			ok=1;
			printf("%s",code[root]);
		}
	}
	printf("\n");
}
int main(){
	scanf("START\n");
	char n_word[15],r_word[15];
	while(scanf("%s",n_word)){
		if(strcmp("END",n_word)==0){
			break;
		}
		getchar();
		gets(r_word);
		in_sert(n_word,r_word);
		memset(n_word,0,sizeof(n_word));
		memset(r_word,0,sizeof(r_word));
	}
	scanf("%s",n_word);
	char w[maxn];
	getchar();
	while(cin.getline(w,maxn,'\n')){
		if(strcmp("END",w)==0){
			return 0;
		}
		Print(w);
	}
	return 0;
}
