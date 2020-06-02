#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1000005
using namespace std;
string str;
int n_next[maxn];
void kmp(string s,int len){
	int k=-1;
	n_next[0]=-1;
	for(int i=1;i<len;i++){
		while(k>-1&&s[k+1]!=s[i]){
			k=n_next[k];
		}
		if(s[k+1]==s[i]){
			k=k+1;
		}
		n_next[i]=k;
	}
}
int main(){
	int t=1;
	int len;
	while(scanf("%d",&len)!=EOF&&len){
		cin>>str;
		kmp(str,len);
		printf("Test case #%d\n",t);
		t++;
		for(int i=0;i<len;i++){
			int ans=(i+1)/((i+1)-(n_next[i]+1));
			if((i+1)%((i+1)-(n_next[i]+1))==0&&ans>1){
				printf("%d %d\n",i+1,ans);
			}
		}
		printf("\n");
	}
} 
