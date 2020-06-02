//已知二叉树的后序遍历和中序遍历，输出该二叉树的先序遍历 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue> 
#define maxn 35
using namespace std;
char post[maxn],in[maxn],left_tree[maxn],right_tree[maxn];
//input:
//7
//2 3 1 5 7 6 4
//1 2 3 4 5 6 7
//output:
//4 1 6 3 5 7 2
int k;
int root;
int build(int i1,int i2,int p1,int p2){
	if(i1>i2||p1>p2)
	return 0;
	char root=post[p2];
	int pa=i1;
	while(in[pa]!=root){
		pa++;
	}
	int cnt=pa-i1;
	cout<<root<<endl;
	left_tree[root]=build(i1,pa-1,p1,p1+cnt-1);
	right_tree[root]=build(pa+1,i2,p1+cnt,p2-1);
	return root;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		getchar();
		for(int i=0;i<n;i++){
			scanf("%c",&post[i]);
			getchar();
		}
		for(int i=0;i<n;i++){
			scanf("%c",&in[i]);
			getchar();
		}
		k=1;
		memset(left_tree,0,maxn);
		memset(right_tree,0,maxn);
		build(0,n-1,0,n-1);
	cout<<"left[4]="<<left_tree[4]<<endl;
	cout<<"right[4]="<<right_tree[4]<<endl;
	cout<<"left[1]="<<left_tree[1]<<endl;
	cout<<"right[1]="<<right_tree[1]<<endl;
	cout<<"left[6]="<<left_tree[6]<<endl;
	cout<<"right[6]="<<right_tree[6]<<endl;
	cout<<"left[3]="<<left_tree[3]<<endl;
	cout<<"right[3]="<<right_tree[3]<<endl;
	cout<<"left[5]="<<left_tree[5]<<endl;
	cout<<"right[5]="<<right_tree[5]<<endl;
	cout<<"left[7]="<<left_tree[7]<<endl;
	cout<<"right[7]="<<right_tree[7]<<endl;	
	cout<<"left[2]="<<left_tree[2]<<endl;
	cout<<"right[2]="<<right_tree[2]<<endl;
		queue<int> q;
		q.push(post[n-1]);
		printf("%d",post[n-1]);
		while(!q.empty()){
			int a=q.front();
			if(a!=post[n-1]){
				printf(" %c",a);
			}
			q.pop();
			if(left_tree[a]!=0){
				q.push(left_tree[a]);
			}
			if(right_tree[a]!=0){
				q.push(right_tree[a]);
			}
		}
		printf("\n");
	}
	return 0;
}
