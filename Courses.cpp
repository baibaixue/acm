#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define maxn 505
using namespace std;
int vis[maxn];
int stu[maxn];
vector<int> link[maxn];
int p,n;
int my_find(int x){
	for(int i=0;i<link[x].size();i++){
		int y=link[x][i];
		if(vis[y]==0){
			vis[y]=1;
			if(stu[y]==0||my_find(stu[y])){
				stu[y]=x;
				return 1;
			}
		}
	}
	return 0;
}
int SUM(){
	int sum=0;
	for(int i=1;i<=p;i++){
		memset(vis,0,sizeof(vis));
		if(my_find(i)){
			sum++;
		}
	}
	return sum;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&p,&n);
		memset(stu,0,sizeof(stu));
		for(int i=1;i<=p;i++){
			link[i].clear();
			int num;
			scanf("%d",&num);
			for(int j=0;j<num;j++){
				int m;
				scanf("%d",&m);
				link[i].push_back(m); 
			} 
		}
		if(p==SUM()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
