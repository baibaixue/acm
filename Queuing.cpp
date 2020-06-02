#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 1000001
using namespace std;
char ans[maxn][31]={0};
int main(){
	int l,m;
		for(int j=1;j<=30;j++){
			ans[0][j]=0%j;
			ans[1][j]=2%j;
			ans[2][j]=4%j;
			ans[3][j]=6%j;
			ans[4][j]=9%j;
		}
	for(int i=5;i<=1000000;i++){
		for(int j=1;j<=30;j++){
			ans[i][j]=(ans[i-1][j]+ans[i-3][j]+ans[i-4][j])%j;
		}
	}
	while(scanf("%d%d",&l,&m)!=EOF){
		printf("%d\n",(int)ans[l][m]);
	}
	return 0;
}
