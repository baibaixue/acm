#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1000000
using namespace std;
char s[maxn];
int main(){
	int n;
	char c;
	while(scanf("%d",&n)!=EOF){
		scanf("%*c%c%*c",&c);
		cin.getline(s,maxn);
		int len=strlen(s);
		if(len<=n){
			for(int i=0;i<n-len;i++){
				printf("%c",c);
			}
			cout<<s<<endl;
		}else{
			for(int i=len-n;i<len;i++){
				printf("%c",s[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
