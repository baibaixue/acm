#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 105
using namespace std;
int num[maxn];
int main(){
	int n;
	scanf("%d",&n);
	int first=0;
	for(int i=0;i<=n;i++){
		scanf("%d",&num[i]);
		if(first==0){
			if(num[i]==0){
				continue;
			}else{
				first=1;
				if(num[i]==1){
					printf("x^%d",n-i);
				}else if(num[i]==-1){
					printf("-x^%d",n-i);
				}else{
					printf("%dx^%d",num[i],n-i);
				}
			}
		}
		else if(first==1){
			if(i!=n&&i!=n-1){
				if(num[i]!=0&&num[i]!=1&&num[i]!=-1){
					if(num[i]>0){
						printf("+");
					}
					printf("%d",num[i]);
					printf("x^%d",n-i);
				}
				else if(num[i]==0){
					continue;
				}else if(num[i]==1){
					printf("+x^%d",n-i);
				}else if(num[i]==-1){
					printf("-x^%d",n-i);
				}
			}
			if(i==n-1){
				if(num[i]!=0&&num[i]!=1&&num[i]!=-1){
					if(num[i]>0){
						printf("+");
					}
					printf("%d",num[i]);
					printf("x");
				}
				else if(num[i]==0){
					continue;
				}else if(num[i]==1){
					printf("+x");
				}else if(num[i]==-1){
					printf("-x");
				}
			}
		}
		if(i==n){
			if(num[i]==0){
				continue;
			}else if(num[i]>0){
				printf("+");
			}
			printf("%d",num[i]);
		}
	}
	printf("\n");
	return 0;
}
