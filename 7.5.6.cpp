#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
using namespace std;
char str[maxn];
char ptr[maxn];
int n_next[maxn];
int len;
void getnext(){
	int k=-1;
	n_next[0]=-1;
	for(int i=-1;i<len;i++){
		while(k>-1&&(str[k+1]+str[i]!='a'+'a'+25)){
			k=n_next[k];
		}
		if(str[k+1]+str[i]=='a'+'a'+25){
			k=k+1;
		}
		n_next[i]=k;
	}
}
int ans=0;
int kmp(){
	getnext();
	int k=0;
	int i=0;
	while(i<len){
		if(k==0||str[k+1]+ptr[i]=='a'+'a'+25){
			i++;
			k++;
		}
		else{
			k=n_next[k];
		}
		ans=max(ans,k);
	}
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		getchar();
		scanf("%s",str);
		len=strlen(str);
		memset(n_next,0,sizeof(n_next));
		for(int i=0;i<len;i++){
			ptr[i]=str[len-i-1];
		} 
	//	getnext();
	//	for(int i=0;i<strlen(str);i++){
	//		printf("%d ",n_next[i]);
	//	}
		printf("\n%d\n",kmp());
	}
} 
