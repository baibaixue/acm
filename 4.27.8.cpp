#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 105
using namespace std;
int n,m;
struct node{
	int x;
	int y;
};
int cnt;
int map[maxn][maxn];
int B[2505];
int A[2505];
//node link[maxn*maxn];
node num[2505];
bool next_box(node a,node b){
	if(fabs(a.x-b.x)+fabs(a.y-b.y)==1){
		return true;
	}
	else{
		return false;
	}
}
int find(int x){
	for(int i=1;i<=cnt;i++){
		if(next_box(num[x],num[i])==true&&B[i]==0){
			B[i]=1;
			if(A[i]==0||find(A[i])){
				A[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int SUM(){
	int sum=0;
	for(int i=1;i<=cnt;i++){
		memset(B,0,sizeof(B));
		if(find(i)){				
			sum++;
		}
	}
	return sum;
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
		int k;
		scanf("%d",&k);
		memset(map,0,sizeof(map));
		memset(A,0,sizeof(A));
		for(int i=0;i<k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			map[x][y]=1;
		}
		cnt=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(map[i][j]==0){
					num[cnt].x=i;
					num[cnt].y=j;
					cnt++;
				}
			}
		}
		int res=SUM();
		printf("%d\n",SUM);
	}
}
