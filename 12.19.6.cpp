#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#define maxn 105
using namespace std;
char map[maxn][maxn];
int main(){
	char x;
	scanf("%c",&x);
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%c",&map[i][j]);
		}
		getchar();
	}
	int no=0;
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]!=map[n-i-1][n-j-1]){
				no=1;
			}
		}
	}
	if(no==0){
		printf("bu yong dao le\n");
	}
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(map[i][j]!=' '){
				printf("%c",x);
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
