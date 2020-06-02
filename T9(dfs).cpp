#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 5000005
using namespace std;
struct node{
	int pro;
	int r;
}tree[maxn][30];
int tot;
char world[1005][105];
bool flag[maxn];
void build(char* s,int p,int x){
	int root=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		int n=s[i]-'a';
		if(tree[root][n].r==0){
			tree[root][n].r=++tot;
			for(int j=0;j<26;j++){
				tree[tot][j].r=0;
				tree[tot][j].pro=0;
			}
		}
		tree[root][n].pro+=p;
		root=tree[root][n].r;
	}
	flag[root]=true;
}
char ans[105];
int sum;
char ff[105];
const string map[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void quest(char* num,int root,int nroot,int len,int now,int cnt){
	if(now==len){
		if(tree[root][cnt].pro>sum){
			sum=tree[root][cnt].pro;
			for(int i=0;i<len;i++){
				ff[i]=ans[i];
			}
			ff[len]='\0';
		}
		return ;
	}
	int t=num[now]-'2';
	for(int i=0;i<map[t].length();i++){
		int id=map[t][i]-'a';
		if(tree[nroot][id].r==0){
			continue;
		}
		ans[now]='a'+id;
		quest(num,nroot,tree[nroot][id].r,len,now+1,id);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		tot=0;
		for(int i=0;i<26;i++){
			tree[0][i].r=0;
			tree[0][i].pro=0;
		}
		memset(flag,false,sizeof(flag));
		memset(world,0,sizeof(world));
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%s",world[i]);
			int p;
			scanf("%d",&p);
			build(world[i],p,i);
		}
		int q;
		scanf("%d",&q);
		printf("Scenario #%d:\n",T);
		char num[15];
		for(int i=0;i<q;i++){
			scanf("%s",num);
			int len=strlen(num);
			for(int k=1;k<=len-1;k++){
				sum=0;
				memset(ans,0,sizeof(ans));
				memset(ff,0,sizeof(ff));
				quest(num,0,0,k,0,0);
				if(sum==0){
					printf("MANUALLY\n");
				}else{
					printf("%s\n",ff);
				}
			}
			printf("\n");
		} 
		printf("\n");
	}
}
