#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std; 
char s[3][10]={{'C','h','u','i','Z','i'},{'J','i','a','n','D','a','o'},{'B','u'}};
int main(){
	int k;
	int t=0;
	while(scanf("%d",&k)!=EOF){
		char c[10];
		cin.getline(c,10);
		if(c[0]=='E'){
			break;
		}
		if(t!=k){	
			if(c[0]=='C'){
				cout<<s[2]<<"\n";
				t++;
			}if(c[0]=='J'){
				cout<<s[0]<<"\n";
				t++;
			}if(c[0]=='B'){
				t++;
				cout<<s[1]<<"\n";
			}
		}else if(t==k){
			if(c[0]=='C'){
				cout<<s[0]<<"\n";
			}if(c[0]=='J'){
				cout<<s[1]<<"\n";
			}if(c[0]=='B'){
				cout<<s[2]<<"\n";
			}
			t=0;
		}
	}
	return 0;
}
