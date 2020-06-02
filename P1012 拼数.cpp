#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
struct ss{
	char s[100];
}num[25];
int cmp(ss a,ss b){
	int lena=strlen(a.s);
	int lenb=strlen(b.s);
	for(int i=0;i<max(lena,lenb);i++){
		if(a.s[i%lena]<b.s[i%lenb]){
			return 1;
		}else if(a.s[i%lena]==b.s[i%lenb]){
			continue;
		}else{
			return 0;
		}
	}
} 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",&num[i].s);
	}
	sort(num,num+n,cmp);
	for(int i=n-1;i>=0;i--){
		printf("%s",num[i].s);
	}
	printf("\n");
	return 0;
}
