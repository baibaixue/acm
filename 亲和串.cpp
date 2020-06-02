#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string s1,s2;
int main(){
	while(getline(cin,s1,'\n')){
		getline(cin,s2,'\n');
		if(s1.length()<s2.length()){
			printf("no\n");
		}else{
			s1=s1+s1;
			if(s1.find(s2)!=-1){
				printf("yes\n");
			}else{
				printf("no\n");
			}
		}
	}
	return 0;
} 
