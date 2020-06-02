#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define maxn 505
using namespace std;
int stu[maxn][maxn];
int vis[maxn];
int link[maxn];
int n;
int find(int x){
	for(int i=0;i<n;i++){
		if(stu[x][i]==1&&vis[i]==0){
			vis[i]=1;
			if(link[i]==-1||find(link[i])){
				link[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int kmp(){
	int sum=0;
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		if(find(i)){
			sum++;
		}
	}
	return sum;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		int m,num,x;
		memset(stu,0,sizeof(stu));
		for(int i=0;i<n;i++){
			scanf("%d: (%d)",&m,&num);
			for(int j=0;j<num;j++){
				scanf("%d",&x);
				stu[m][x]=1;
			}
		}
		for(int i=0;i<n;i++){
			link[i]=-1;
		}
		int ans=kmp();
		printf("%d\n",n-ans/2);
	}
	return 0;
}

