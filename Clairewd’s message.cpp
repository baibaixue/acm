#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define maxn 100005
using namespace std;
string words;
char MAP[26];
string WORDS;
int Next[maxn];
int Len;
void getnext(){
	int k=-1;
	Next[0]=-1;
	for(int i=1;i<Len;i++){
		while(k>-1&&words[i]!=WORDS[k+1]){
			k=Next[k];
		}
		if(words[i]==WORDS[k+1]){
			k++;
		}
		Next[i]=k;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		WORDS.clear();
		for(int i=0;i<26;i++){
			char c;
			scanf("%c",&c);
			MAP[c-'a']=i+'a';
		}
		getchar();
		getline(cin,words);
		Len=words.length();
		for(int i=0;i<Len;i++){
			WORDS+=MAP[words[i]-'a'];
		}
		getnext();
		int ans=Next[Len-1]+1;
		if(ans==Len-1){
			ans=Len/2;
		}
	cout<<words.substr(0,Len-ans)<<WORDS.substr(0,Len-ans)<<endl; 
	}
	return 0;
}
