#include<stdio.h>
#include<string.h> 
int main(){
	int c[40][40];
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(c,0,sizeof(c));
		for(int i=0;i<n+1;i++){
			c[i][0]=1;
		}
		for(int i=1;i<n+1;i++){
			for(int j=1;j<i;j++){
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
		}
		for(int i=1;i<n+1;i++){
			printf("%d",c[i][0]);
			for(int j=1;j<i;j++){
				if(c[i][j]!=0){
					printf(" %d",c[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
