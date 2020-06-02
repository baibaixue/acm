#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std; 

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			char s[5];
			int h,m;
			scanf("%s",s);
			scanf("%d%d",&h,&m);
			if(h>=15&&h<=20&&m>=50&&m<=70){
			}
			else{
				cout<<s<<"\n"; 
			}
		}
	}
	return 0;
}
