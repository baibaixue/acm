#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n;
	char s[55];
	scanf("%d",&n);
	getchar();
	while(n--){
		cin.getline(s,55,'\n');
		int len=strlen(s);
		for(int i=len-1;i>=0;i--){
			printf("%c",s[i]);
		} 
		printf("\n");
	}
	return 0;
}
