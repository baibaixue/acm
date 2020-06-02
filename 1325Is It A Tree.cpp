#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10000
using namespace std;
int endroot[maxn];//判断是否有节点被指向两次 
struct s{
	int n;
	int visit;
}tree[maxn];
int find(int x){
	int r=x;
	while(r!=tree[r].n){
		r=tree[r].n;
	}
	return r;
}
int hebing(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		tree[b].n=a;
		return 1;
	}else if(a==b){//判断是否为环 
		return 0;
	}
}
int main(){
	for(int k=1;;k++){
		int a,b;
		for(int i=0;i<maxn;i++){
			tree[i].n=i;
			tree[i].visit=0;
			endroot[i]=0;
		}
		scanf("%d%d",&a,&b);
		tree[a].visit=1;
		tree[b].visit=1;
		endroot[b]=1;
		if(a==0&&b==0){//空树的情况 
			printf("Case %d is a tree.\n",k);
			continue;
		}
		if(a<0&&b<0){
			break;
		}
		int no=0;
		do{
			int is_tree=hebing(a,b);//环的情况 
			tree[a].visit=1;
			tree[b].visit=1;
			if(is_tree==0){
				no=1;
			}
			scanf("%d%d",&a,&b);
			if(endroot[b]==1){
				no=1;
			}else{
				endroot[b]=1;
			}
		}while(a!=0&&b!=0);
		int count=0;
		for(int i=1;i<maxn;i++){
			if(tree[i].visit==1){//判断是否有多个根节点 
				if(tree[i].n==i){
					count++;
				}
			}
		}
		if(count>1){
			no=1;
		}
		if(no==1){
			printf("Case %d is not a tree.\n",k);
		}else{
			printf("Case %d is a tree.\n",k);
		}
	}
	return 0; 
}
