#include<stdio.h>
#include<string.h>
char s[10010];
int b[10];

int main(){
	while(scanf("%s",s)!=EOF){
		memset(b,0,sizeof(b));
		int n=strlen(s);
		for(int i=0;i<n;i++){
			b[s[i]-'0']++;
		} 
		for(int i=0;i<10;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	return 0;
}
