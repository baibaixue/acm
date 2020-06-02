#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#define max_n 100000+10
using namespace std;
char s[max_n],t[max_n];
char ans[max_n];
void mins(char* a,char* b,int n){
	for(int i=0;i<n;i++){
		if(a[i]<b[i]){
			strcpy(ans,a);
		}else if(a[i]>b[i]){
			strcpy(ans,b);
		}
	}
}
int main(){
	while(cin.getline(s,max_n)&&cin.getline(t,max_n)){
		int len=strlen(s);
		mins(s,t,len);
		if(ans[len-1]<'Z'){
			for(int i=0;i<len-1;i++){
				printf("%c",ans[i]);
			}
			printf("%c",ans[len-1]+1);
		}
		else{
			for(int i=len-2;i>=0;i--){
				if(ans[i]!='Z'){
					ans[i]=ans[i]+1;
					break; 
				}
			}
			for(int i=0;i<len;i++){
				printf("%c",ans[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
