#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 1000010
using namespace std;
char str[maxn];
int len;
int n_next[maxn];
void build_next(){
	int k=-1;
	int i=0;
	n_next[0]=-1;
	while(i<len){
		if(k==-1||str[k]==str[i]-25||str[k]==str[i]+25){
			k++;
			i++;
			n_next[i]=k;
		}
		else{
			k=n_next[k];
		}
	}
}
int kmp(){
	build_next();
	int k=0;
	int i=0;
	while(i<len){
		if(k==-1||str[i]==str[k]){
			i++;
			k++;
		}
		else{
			k=n_next[k];
		}
		if(k==len){
			return i-len+1;
		}
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(n_next,0,sizeof(n_next));
		scanf("%s",str);
		len=strlen(str);
			int ans=kmp();
			printf("%d\n",ans);
		}
} 
