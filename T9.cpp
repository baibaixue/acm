#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 5000005
using namespace std;
struct node{
	int id;
	int pro;
	int r;
}tree[maxn][30];
int tot;
char world[1005][105];
void build(char* s,int p,int x){
	int root=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		int n=s[i]-'a';
		if(tree[root][n].r==0){
			tree[root][n].r=++tot;
			for(int j=0;j<26;j++){
				tree[tot][j].r=0;
				tree[tot][j].id=-1;
				tree[tot][j].pro=0;
			} 
		}
		if(p>tree[root][n].pro){
				tree[root][n].pro+=p;
				tree[root][n].id=x;
			}
		root=tree[root][n].r;
	}
}
struct Node{
	int deep;//读取到数字的长度 
	int c;//当前数字 
	int id;//当前最可能的字符串的编号 
	int pro;//当前字符串的概率 
	int r;//当前在字典树中的节点 
};
const string map[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
struct ANS{
	int pro;
	int id;
}ans[105];
void quest(char* s,int len){/*bfs 错 应用dfs做 */ 
	queue<Node>Q;
	Node now,next;
	now.c=s[0]-'0';
	now.r=0;
	now.deep=1;
	for(int i=0;i<(map[now.c].length());i++){
		int num=map[now.c-2][i]-'a';
		now.r=0;
		if(tree[now.r][num].r!=0){
			now.id=tree[now.r][num].id;
			now.pro=tree[now.r][num].pro;
			now.r=tree[now.r][num].r;
			Q.push(now);
		}
	}
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		if(ans[now.deep].pro<now.pro){
			ans[now.deep].pro=now.pro;
			ans[now.deep].id=now.id;
		}
		if(now.deep<=len-2){
			next.c=s[now.deep]-'0';
			next.deep=now.deep+1;
			for(int i=0;i<(map[next.c-2].length());i++){
				int num=map[next.c-2][i]-'a';
				next.r=now.r;
				next.id=now.id;
				next.pro=now.pro;
				if(tree[next.r][num].r!=0){
					if(tree[next.r][num].pro>next.pro){
						next.pro=tree[next.r][num].pro;
						next.id=tree[next.r][num].id;
						next.r=tree[next.r][num].r;
						Q.push(next); 
					}
					next.r=tree[next.r][num].r;
					Q.push(next);
				}
			}
		}
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
			tree[0][i].id=-1;
		}
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
			for(int k=0;k<10;k++){
				ans[k].id=0;
				ans[k].pro=0;
			}if(len==1&&num[0]=='1'){
				printf("MANUALLY\n");
			} 
			else{
				quest(num,len);
				for(int k=1;k<=len-1;k++){
					if(ans[k].pro!=0){
						for(int j=0;j<k;j++){
							printf("%c",world[ans[k].id][j]);
						}
					}else{
						printf("MANUALLY");
					}
					printf("\n");
				}
			}
			printf("\n");
		} 
	}
}
