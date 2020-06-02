#include<stdio.h>
#include<string.h>
#include<ctype.h>
const char* s="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* a[]={"--is not a palindrom.","--is a regular palindrom.","--is a mirrored string.","--is a mirrored palindrom."};
char mirror(char c){
	if (isalpha(c)){
		return s[c-'A']; 
	}else{
		return s[c-'0'+25];
	}
}
int main(){
	char c[30];
	while(scanf("%s",c)!=EOF){
		int p=1,q=1;
		int n=strlen(c);
		for(int i=0;i<n/2;i++){
			if(c[i]!=c[n-i-1]){
				p=0;
			}
			if(mirror(c[i])!=c[n-i-1]){
				q=0;
			}
		}
		printf("%s--%s\n\n",c,a[q*2+p]);
	}
	return 0;
}
