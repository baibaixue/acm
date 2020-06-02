#include<stdio.h>
#include<string.h>
char s[100];
int main(){
	while(scanf("%s",s)!=EOF){
		int k;
		for(k=1;k<strlen(s);k++){
			int t=1;
			for(int i=0;i<strlen(s)&&(i+k)<strlen(s);i++){
				if(s[i]!=s[i+k]){
					t=0;
					break; 
				}
			}
			if(t==1){
				break;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
