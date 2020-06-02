#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			for(int j=0;j<s.size();j++){
				if(s[j]!='a'&&s[j]!='e'&&s[j]!='i'&&s[j]!='o'&&s[j]!='u'&&s[j]!='y'){
					printf("%c",s[j]);
				}else if(j==0){
					printf("%c",s[j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
