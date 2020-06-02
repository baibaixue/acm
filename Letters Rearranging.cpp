#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char s[1005];
		scanf("%s",s);
		int len=strlen(s);
		sort(s,s+len);
		if(s[0]==s[len-1]){
			printf("-1\n");
		}else{
			printf("%s\n",s);
		}
	}
	return 0;
}
