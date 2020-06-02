#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1000005
using namespace std;
int main(){
	char word[13]; 
	char essay[maxn];
	cin.getline(word,13);
	cin.getline(essay,maxn);
	int len1=strlen(word);
	int len2=strlen(essay);
	for(int i=len1;i>0;i--){
		word[i]=word[i-1];
	}
	for(int i=len2;i>0;i--){
		essay[i]=essay[i-1];
	}
	word[0]=' ';
	essay[0]=' ';
	len1++;
	len2++;
	word[len1]=' ';
	essay[len2]=' ';
	len1++;
	len2++;
	int cnt=0;
	int fir=0;
	for(int i=0;i<len2;i++){
		int l=i;
		for(int j=0;j<len1;j++){
			if(word[j]!=essay[l]&&(char)(word[j]+32)!=essay[l]&&(char)(word[j]-32)!=essay[l]){
				break;
			}
			if(l-i==len1-1){
				if(cnt==0){
					fir=i;
				}
				cnt++;
			}
			l++;
		}
	}
	if(cnt==0){
		printf("-1\n");
	}else{
		printf("%d %d",cnt,fir);
	}
	return 0;
}
