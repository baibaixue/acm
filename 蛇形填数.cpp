#include<stdio.h>
#include<string.h>
int main(){
	int a[10][10];
	int n;
	int x,y;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		a[x=0][y=n-1]=1;
		int i=1;
		while(i<n*n){
			while(x+1<n&&!a[x+1][y]) a[++x][y]=++i;
			while(y-1>=0&&!a[x][y-1]) a[x][--y]=++i;
			while(x-1>=0&&!a[x-1][y]) a[--x][y]=++i;
			while(y+1<n&&!a[x][y+1]) a[x][++y]=++i;
		}
		for(x=0;x<n;x++){
			for(y=0;y<n;y++){
				printf("%3d",a[x][y]);
			}
			printf("\n");
		}
	}
	return 0;
} 
