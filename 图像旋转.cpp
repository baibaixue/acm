#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 1005
using namespace std;
int a [maxn][maxn];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}			
		}
		for(int i=m-1;i>=0;i--){
			for(int j=0;j<n;j++){
				printf("%d",a[j][i]);
				if(j<n){
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}

