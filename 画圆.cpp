#include<stdio.h>//ÊäÈër<x/2=y/2 
#include<math.h> 
#define x 40 
#define y 40 
int main(){
	int a[x][y];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			a[i][j]=' '; 
		}
	}
	int r;
	int n,m;
	scanf("%d",&r);
	for(n=0;n<x;n++){
		for(m=0;m<y;m++){
			if(floor(sqrt((n-x/2)*(n-x/2)+(m-y/2)*(m-y/2))+0.5)==r){
				a[n][m]='*';
			}
		}
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			printf(" %c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
