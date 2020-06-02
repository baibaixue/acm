#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
char c[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main(){
	char ans[10];
	int l;
	int n;
	int k=0;
	scanf("%d%d",&l,&n);
	int x=pow(26,l)-n;
	for(int i=0;i<l;i++){
		ans[k++]=c[x%26];
		x=x/26;
	}
	for(int i=l-1;i>=0;i--){
		printf("%c",ans[i]);
	}
	printf("\n");
	return 0;
}
