#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005 
using namespace std;
string s;
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		cin>>s;
		int cnt=0;
		int ans=0;
		int len=s.length();
		for(int i=0;i<len;i++){
			int a=i;
			for(int j=len-1;j>=i;j--){
				if(s[a]=='z'-s[j]+'a'||a==j){
					cnt++;
					a++;
					if(i==j){
						if(ans<cnt){
							ans=cnt;
						}
						cnt=0;
					}
				}else{
					cnt=0;
					a=i;
					continue;
				}	
			}
		}
		printf("%d\n",ans);
	}
} 
