#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 500005
using namespace std;
int tree[maxn][90];
char code[maxn][15];
int flag[maxn];
int tot;
void in_sert(char* str1,char* str2){
	int root=0;
	int len=strlen(str2);
	for(int i=0;i<len;i++){
		int id=str2[i]-'\a';
		if(tree[root][id]==0){
			tree[root][id]=++tot;
		}
		root=tree[root][id];
	}
	flag[root]=1;
	strcpy(code[root],str1); 
	return ;
}
void transfer(char* s){
	int root=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		int id=s[i]-'\a';		
		if(tree[root][id]!=0){
			for(int j=i;j<=len;j++){
				id=s[j]-'\a';
				if(flag[root]==1&&(j==len||s[j]<'a'||s[j]>'z')&&(i==0||s[i-1]<'a'||s[i-1]>'z')){
					printf("%s",code[root]);
					i=j-1;
					root=0;
					break;
				}
				if(root!=0&&tree[root][id]==0){
					printf("%c",s[i]);
					root=0;
					break;
				}
				if(tree[root][id]!=0){
					root=tree[root][id];
				}
				
				if((i==0||s[i-1]<'a'||s[i-1]>'z')&&(j==len||s[j]<'a'||s[j]>'z')&&root!=0){
					printf("%c",s[i]);
					root=0;
					break;
				}
			}
		}else printf("%c",s[i]);
	}
	printf("\n");
}
int main(){
	while(scanf("START")!=EOF){
		char s1[15],s2[15];
		memset(tree,0,sizeof(tree));
		memset(flag,0,sizeof(flag));
		memset(code,0,sizeof(code));
		while(scanf("%s %s",s1,s2)!=EOF&&strcmp("END",s1)!=0){
			in_sert(s1,s2);
			memset(s1,0,sizeof(s1));
			memset(s2,0,sizeof(s2));
		}
		//printf("START\n");
		char w[3005];
		getchar();
		while(cin.getline(w,3005,'\n')){
			if(strcmp("END",w)==0){
				break;
			}
			transfer(w);
		}
	}
	return 0; 
}
