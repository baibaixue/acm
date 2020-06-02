#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
char num[1010];
int n[10];
int main(){
	memset(n,0,sizeof(n));
	scanf("%s",num);
	int len=strlen(num);
	for(int i=0;i<len;i++){
		n[(int)(num[i]-'0')]++;
	}
		for(int i=0;i<10;i++){
			if(n[i]!=0){
				printf("%d:%d\n",i,n[i]);
			}
		}
	return 0;
} 
