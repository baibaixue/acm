#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 505
using namespace std;
int A[maxn],B[maxn];
int link[maxn][maxn];
int m,n;
int find(int x){
	for(int i=1;i<=n;i++){
		if(link[x][i]!=0&&B[i]==0){
			B[i]=1;
			if(A[i]==0||find(A[i])){
				A[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int k;
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d%d",&m,&k);
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(link,0,sizeof(link));
		for(int i=0;i<k;i++){
			int c,a,b;
			scanf("%d%d%d",&c,&a,&b);
			link[a][b]=1;
			//link[b][g]=1;
		}
		int sum=0;
		for(int i=1;i<=m;i++){
			memset(B,0,sizeof(B));
			if(find(i)){
				sum++;
			}
		}
		printf("%d\n",sum);
	}
} 
