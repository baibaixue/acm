#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std; 
char s[1000];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		scanf("%*c");
		while(n--){
			int count=0;
			gets(s);
			int len=strlen(s);
			for(int i=0;i<len;i++){
				if(s[i]<0){
					count++;
				}
			}
			printf("%d\n",count/2);
		}
	} 
	return 0;
}
