#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	while(scanf("%s",s)!=EOF){
		int count=0;
		int sum=0;
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='O'){
				count++;
				sum+=count;
			}else if(s[i]=='X'){
				count=0;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
	
} 
