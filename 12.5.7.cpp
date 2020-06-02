#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1005
using namespace std; 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		getchar();
		char s[maxn];
		char ss[102][102];
		int visit [102][102];
		//memset(ss,' ',sizeof(ss));
		memset(visit,0,sizeof(visit));
		cin.getline(s,maxn);
		int len=strlen(s);
		int k=0;
		int l=0;
		while(l<len){
			for(int j=0;j<n;j++){
				if(l<len){
					ss[k][j]=s[l++];
				}
				else{
					ss[k][j]=' ';
				}
				visit[k][j]=1;
			}
			k++; 
		}
		for(int j=0;j<n;j++){
			for(int i=k-1;i>=0;i--){
				if(visit[i][j]==1)
				printf("%c",ss[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
