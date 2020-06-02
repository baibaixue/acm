#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 4000005
using namespace std;
struct node{
	int id;
	int cnt;
	int a[30];
}tree[maxn];
int tot;
void build(char* s,int len,int x){
	int root=0;
	for(int i=0;i<len;i++){
		int num=s[i]-'a';
		if(tree[root].a[num]==0){
			tree[root].a[num]=++tot;
			for(int j=0;j<26;j++){
				tree[tot].a[j]=0;
			}
			tree[tot].id=-1;
			tree[tot].cnt=0;
		}
		root=tree[root].a[num];
		if(tree[root].id!=x){
			tree[root].cnt++;
		}
		tree[root].id=x;
	}
}
int quest(char* s){
	int root=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		int num=s[i]-'a';
		if(tree[root].a[num]!=0){
			root=tree[root].a[num];
		}else{
			return 0;
		}
	} 
	return tree[root].cnt; 
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		tot=0;
		char s[50];
		for(int i=0;i<26;i++){
			tree[0].a[i]=0;
		}
		tree[0].id=-1;
		tree[0].cnt=0;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			int len=strlen(s);
			for(int j=0;j<len;j++){
				build(s+j,len-j,i);
			}
			
		}
		int q;
		scanf("%d",&q);
		char ss[50];
		for(int i=0;i<q;i++){
			scanf("%s",s);
			printf("%d\n",quest(s));
		}
	}
	return 0;
} 
