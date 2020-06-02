#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool find (char *s1, char *s2){
	int len1=strlen(s1);
	int len2=strlen(s2);
	if(len1>len2){
		return false;
	}
	else{
		for(int i=0;i<len2-len1+1;i++){
			for(int j=0;j<len1;j++){
				if(s2[i+j]!=s1[j]){
					break;
				}
				if(j==len1-1){
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		char s[205][105];	
		for(int i=0;i<n;i++){
			char temp[105];
			scanf("%s",s[i]);
			if(i>=1){
				for(int j=strlen(s[i])-1;j>=0;j--){
					s[100+i][strlen(s[i])-j-1]=s[i][j];
				}
			}
		}
		int ans=0;
		int len=0;
		for(int i=0;i<strlen(s[0]);i++){
			for(int k=1;i+k<=strlen(s[0]);k++){
				char temp[105];
				memset(temp,0,sizeof(temp));
				memcpy(temp,s[0]+i,k);
				len=strlen(temp);
				for(int j=1;j<n;j++){
					if(!(find(temp,s[j])||find(temp,s[j+100]))){
						len=0;
						break;
					}
				}
				if(len>ans){
					ans=len;
				}
			}
		}
		printf("%d\n",ans);
	}
}
