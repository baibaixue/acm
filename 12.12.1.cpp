#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std; 
int main(){
	int n;
	int k=0;
	int ans=0;
	char c;
	while(scanf("%d",&n)!=EOF){
		k++;
		if(n==250&&ans==0){
			ans=k;
		}
		scanf("%c",&c);
		if(c=='\n'){
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
