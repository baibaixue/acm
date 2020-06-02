#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#define max 1020
using namespace std;
int main(){
	char s[max];
	int c[max]; 
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		int n=0;
		s[len]='5';
		memset(c,0,sizeof(c));
		int k=0;
		for(int i=0;i<=len;i++){
			if(s[i]!='5'){
				c[n]=(int)(s[i]-'0')+c[n]*10;
				k=1;
				if(s[i+1]=='5'){
					if(k==1){
						n++;
					}
				}
			}
			
		}
		sort(c,c+n);
		int i=0;
		while(i<n-1){
			printf("%d ",c[i]);
			i++;
		}
		printf("%d\n",c[n-1]);
	}
	return 0;
}
