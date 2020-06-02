#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 1000010
using namespace std;
int str[maxn];
int ptr[maxn];
int slen,plen;
int n_next[maxn];
void build_next(){
	int k=-1;
	int i=0;
	n_next[0]=-1;
	while(i<plen){
		if(k==-1||ptr[k]==ptr[i]){
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
	while(i<slen){
		if(k==-1||str[i]==ptr[k]){
			i++;
			k++;
		}
		else{
			k=n_next[k];
		}
		if(k==plen){
			return i-plen+1;
		}
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(n_next,0,sizeof(n_next));
		scanf("%d%d",&slen,&plen);
		for(int i=0;i<slen;i++){
			scanf("%d",&str[i]);
		}
		for(int i=0;i<plen;i++){
			scanf("%d",&ptr[i]);
		}
		if(plen>slen){
			printf("-1\n");
		}else{
			int ans=kmp();
			printf("%d\n",ans);
		}
		
	}
} 
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 1000010
using namespace std;
int str[maxn];
int ptr[maxn];
int slen,plen;
int n_next[maxn];
void build_next(){
	int k=-1;
	int i=0;
	n_next[0]=-1;
	while(i<plen){
		if(k==-1||ptr[k+1]==ptr[i]){
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
	while(i<slen){
		if(k==0||str[i]==ptr[k]){
			i++;
			k++;
		}
		else{
			k=n_next[k];
		}
		if(k==plen-1){
			return i-plen+1;
		}
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(n_next,0,sizeof(n_next));
		scanf("%d%d",&slen,&plen);
		for(int i=0;i<slen;i++){
			scanf("%d",&str[i]);
		}
		for(int i=0;i<plen;i++){
			scanf("%d",&ptr[i]);
		}
		if(plen>slen){
			printf("-1\n");
		}else{
			int ans=kmp();
			printf("%d\n",ans);
		}
		
	}
} 
*/

