#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
#define maxn 105
using namespace std; 
int A[maxn][maxn];
int B[maxn][maxn];
int main(){
	int ca,cb,ra,rb;
	while(scanf("%d%d",&ra,&ca)!=EOF){
		for(int i=1;i<=ra;i++){
			for(int j=1;j<=ca;j++){
				scanf("%d",&A[i][j]);
			}
		}
		scanf("%d%d",&rb,&cb);
		for(int i=1;i<=rb;i++){
			for(int j=1;j<=cb;j++){
				scanf("%d",&B[i][j]);
			}
		}
		if(ca!=rb){
			printf("Error: %d != %d\n",ca,rb);
		}
		else{
			printf("%d %d\n",ra,cb);
			for(int i=1;i<=ra;i++){
				for(int j=1;j<=cb;j++){
					int a=0;
					for(int k=1;k<=ca;k++){
						a+=A[i][k]*B[k][j];
					}
					printf("%d",a);
					if(j!=cb){
						printf(" ");
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
