#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[25][25];
int dp[25][200000];
int q[200000]; 
int main(){ 
	int n;
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int cont=0;
        int end=1<<n;
        for(int i=0;i<end;i++){
            if((i&(i<<1))==0){
                q[cont++]=i;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<cont;j++){
                int sum=0;
                for(int k=0;k<n;k++){
                    if((q[j]&(1<<k))!=0){
                        sum+=a[i][k];
                    }
                }
                dp[i][j]=sum;
                if(i>=1){
                	for(int k=0;k<cont;k++){
	                	if((q[j]&q[k])==0){
	                		dp[i][j]=max(dp[i][j],dp[i-1][k]+sum);
						}
					}
				}
            }
    	}
    	int ans=0;
    	for(int i=0;i<cont;i++){
    		ans=max(ans,dp[n-1][i]);
		}
		printf("%d\n",ans);
	}
} 
