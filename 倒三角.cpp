#include<stdio.h>
int main(){
	int n,x;
	char  a=' ';
	while(scanf("%d",&n)!=EOF){
		for(int i=n;i>0;i--){
			x=2*i-1;
				for(int m=n;m>i;m--){
					printf("%c",a);
				}
				for(int j=0;j<x;j++){
					printf("#");
				}
				printf("\n");
			}
		}
		return 0;
	}
