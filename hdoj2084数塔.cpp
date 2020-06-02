#include<stdio.h>
#include<string.h>
#define maxn 120
int c[maxn][maxn];
int s[maxn];
int main(){
	int n;
	int x;
	scanf("%d",&x);
		while(x--){
			scanf("%d",&n);
			memset(c,0,sizeof(c));
			memset(s,0,sizeof(s));
			for(int i=0;i<n;i++){
				for(int j=0;j<=i;j++){
					scanf("%d",&c[i][j]);
				}
			}for(int i=n-2;i>=0;i--){
				for(int j=0;j<=i;j++){
					if(c[i+1][j]>c[i+1][j+1]){
						c[i][j]+=c[i+1][j];
					}else{
						c[i][j]+=c[i+1][j+1];
					}
				}
			}
			printf("%d\n",c[0][0]);
	}
} 
