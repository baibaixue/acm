#include<cstdio>
#include<cstring>
#define max 1020
char c[max];
int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		memset(c,0,strlen(c));
		for(int i=0;i<t;i++){
			scanf("%d",&c[i]);
		}
		for(int i=0;i<t;i++){
			printf("%c",c[i]);
		}
	}
	return 0;
}
