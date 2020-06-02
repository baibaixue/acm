#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 10000+50
using namespace std;
char a[maxn],b[maxn];
int main(){
	while(cin.getline(a,maxn)){
		cin.getline(b,maxn);
		int len1=strlen(a);
		int len2=strlen(b);
		for(int i=0;i<len1;i++){
			int k=1;
			for(int j=0;j<len2;j++){
				if(a[i]==b[j]){
					k=0;
				}
			}
			if(k==1){
				printf("%c",a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
