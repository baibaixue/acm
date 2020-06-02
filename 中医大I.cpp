#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	const char s[10]={'z','a','i','l','a','i','y','i','h','e'};
	int n;
	scanf("%d",&n);
	getchar();
	int cnt=0;
	while(n--){
		char c[1005];
		scanf("%s",c);
		getchar(); 
		int len=strlen(c);
		for(int i=0;i<=len-10;i++){
			int ok=1;
			for(int j=0;j<10;j++){
				if(c[i+j]!=s[j]){
					ok=0;
					break;
				}
			}
			if(ok==1){
				cnt++;
				break;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
