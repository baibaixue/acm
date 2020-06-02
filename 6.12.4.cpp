#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std; 
int dp[1050];
int j[1050];
int f[1050];
int main(){
	int M,N;
	while(scanf("%d%d",&M,&N)!=EOF){
		if(M==-1&&N==-1){
			break;
		}
		memset(dp,0,sizeof(dp));
		memset(j,0,sizeof(j));
		memset(f,0,sizeof(f));
		for(int i=1;i<=N;i++){
			scanf("%d%d",&j[i],&f[i]);
		}
	  	 for(int i=1;i<=N;i++){
	  	 	for(int c=M;c>=0;c--){
		  	 	if(c>=f[i]){
		        	dp[c]=max(dp[c],dp[c-f[i]]+j[i]);
				}
			}
		}  
		int maxx=-1;
		for(int i=0;i<=M;i++){
			if(dp[i]>maxx){
				maxx=dp[i];
			}
		}
		printf("%d\n",maxx);
	} 
}
