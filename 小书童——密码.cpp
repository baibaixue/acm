#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	char s[55];
	scanf("%s",s);
	int a;
	for(int i=0;s[i]!='\0';i++){
		a=n;
		while(!(s[i]+a<='z'&&s[i]+a>='a')){
			int x='z'-s[i]+1;
			s[i]='a';
			a=a-x;
		}
		s[i]=s[i]+a;
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
} 
