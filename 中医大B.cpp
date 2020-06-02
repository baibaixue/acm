#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1105
using namespace std;
int N[maxn];
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		N[0]=0;
		int k=m;
		for(int i=1;i<=n;i++){
			if(k!=0){
				N[i]=1;
				k--;
			}else{
				N[i]=0;
				k=m;
			}
		}
		if(n<=m){
			for(int i=n;i<m;i++){
				printf("%d ",i);
			}
			printf("%d",m);
		}else{
			if(N[n]!=0){
				int count=0;
				for(int i=n-1;i>=max(n-m,0);i--){
					if(N[i]==0){
						count++;
					}
				}
				for(int i=n-1;i>=max(n-m,0);i--){
					if(N[i]==0){
						printf("%d",n-i);
						count--;
						if(count!=0){
							printf(" ");
						}
					}
				}
			}else{
				printf("You are loser\n");
			}
		}
		printf("\n");
	}
	return 0;
}
