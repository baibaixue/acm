#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<string.h> 
using namespace std;
int a[26];
int b[26];
int main(){
	string str1,str2;
	while(cin>>str1>>str2){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		if(str1==str2){
			printf("Equal\n");
		}else{
			if(str1[0]==str2[0]&&str1[str1.length()-1]==str2[str2.length()-1]){
				int ok=1;
				for(int i=0;i<str1.length();i++){
					a[str1[i]-'a']++;
				}
				for(int i=0;i<str2.length();i++){
					b[str2[i]-'a']++;
				}
				for(int i=0;i<26;i++){
					if(a[i]!=b[i]){
						ok=0;
					}
				}
				if(ok==1){
					printf("Yes\n");
				}else{
					printf("No\n");
				}
			}
			else{
				printf("No\n");
			}
		}
	}
}
