#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 505
using namespace std;
int boy[maxn],girl[maxn];
int link[maxn][maxn];
int m,n;
int find(int x){
	for(int i=1;i<=n;i++){
		if(link[x][i]!=0&&boy[i]==0){
			boy[i]=1;
			if(girl[i]==0||find(girl[i])){
				girl[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int k;
	while(scanf("%d",&k)!=EOF&&k){
		scanf("%d%d",&m,&n);
		memset(girl,0,sizeof(girl));
		memset(boy,0,sizeof(boy));
		memset(link,0,sizeof(link));
		for(int i=0;i<k;i++){
			int g,b;
			scanf("%d%d",&g,&b);
			link[g][b]=1;
			//link[b][g]=1;
		}
		int sum=0;
		for(int i=1;i<=m;i++){
			memset(boy,0,sizeof(boy));
			if(find(i)){
				sum++;
			}
		}
		printf("%d\n",sum);
	}
} 
