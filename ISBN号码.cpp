#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	char s[15];
	scanf("%s",s);
	int x=0;
	int n=0;
	for(int i=0;i<12;i++){
		if(s[i]!='-'){
			x+=(int)(s[i]-'0')*(++n);
		}
	}
	x=x%11;
	char a;
	if(x==10){
		a='X';
	}else{
		a=(char)(x+'0');
	}
	if(a==s[12]){
		printf("Right\n");
	}else{
		for(int i=0;i<12;i++){
			printf("%c",s[i]);
		}
		printf("%c\n",a);
	}
	return 0;
}
