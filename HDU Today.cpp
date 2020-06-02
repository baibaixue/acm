#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10002
#define inf 0x3f3f3f3f
using namespace std;
char station[151][31];
int dp[155][155];
int f;
int num(char *word){
	for(int i=1;i<=f;i++){
		if(strcmp(word,station[i])==0){
			return i;
		}
	}
		strcpy(station[++f],word);
		return f;
}
void floyd(){
	for(int k=1;k<=f;k++){
		for(int i=1;i<=f;i++){
			for(int j=1;j<=f;j++){
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	}
	return ;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=-1){
		getchar();
		f=0;
		memset(dp,inf,sizeof(dp));
		memset(station,0,sizeof(station));
		for(int i=1;i<155;i++){
			dp[i][i]=0;
		}
		char s[32];char e[32];int t;
		scanf("%s",s);
		scanf("%s",e);
		int S=num(s);
		int E=num(e);
		memset(s,0,sizeof(s));
		memset(e,0,sizeof(e));
		int a,b;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			scanf("%s",e);
			scanf("%d",&t);
			a=num(s);b=num(e);
			memset(s,0,sizeof(s));
			memset(e,0,sizeof(e));
			dp[a][b]=min(dp[a][b],t);
			dp[b][a]=dp[a][b];
		}
		floyd();
		if(dp[S][E]==inf){
			printf("-1\n");
		}else{
			printf("%d\n",dp[S][E]);
		}
	}
	return 0;
}
