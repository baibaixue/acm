#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 205
using namespace std;
struct S{
	char s[maxn];
	char is;
}num[maxn];
int is_f(char *f,int a){
	int len=strlen(num[a].s);
	int isok=1;
	for(int i=0;i<len;i++){
		if(!(f[i]==num[a].s[i]||f[i]=='\0')){
			isok=0;
		}
	}
	if(isok==1){
		return 1;
	}else
		return 0;
}
int is_n(char *ne,int a,int n){
	int len=strlen(num[a].s);
	int isok=1;
	int L=len;
	for(int i=0;i<L;i++){
		if(!(f[n-1]==num[a].s[len-1]||f[n-1]=='\0')){
			isok=0;
			n--;
			len--;
		}
	}
	if(isok==1){
		return 1;
	}else
		return 0;
}
int main(){
	int n;
	char f[maxn];
	char ne[maxn];
	while(scanf("%d",&n)!=EOF){
		getchar();
		for(int i=0;i<n*2-2;i++){
			cin.getline(num[i].s,maxn);
		}
		int len=strlen(num[0].s);
		int L=len;
		int a=n-1;
		for(int i=0;i<L;i++){
			f[i]=num[0].s[i];
			ne[a--]=num[0].s[--len];
		}
		num[0].is=1;
		for(int i=1;i<2*n-2;i++){
			int len=strlen(num[i].s);
			if(num[i].s[i]==f[0]&&num[i].s[len-1]!=ne[n-1]){
				num[i].is=!(num[0].is);
			}if(num[i].s[i]!=f[0]&&num[i])
		}
	}
}
