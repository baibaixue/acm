#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 100
using namespace std;
char words[maxn][2];
int visit[maxn];
int bfs(int n){
	queue<char>Q;
	Q.push('b');
	char last,next;
	while(!Q.empty()){
		last=Q.front();
		Q.pop();
		if(last=='m'){
			return 1;
		}
		for(int i=0;i<n;i++){
			if(words[i][0]==last&&visit[i]==0){
				next=words[i][1];
				Q.push(next);
				visit[i]=1;
			}
		}
	} 
	return 0;
}
int main(){
	char word[maxn];
	int a;
	while(scanf("%s",word)!=EOF){
		a=0;
		words[a][0]=word[0];
		words[a][1]=word[strlen(word)-1];
		while(scanf("%s",word)&&word[0]!='0'){
			a++;
			words[a][0]=word[0];
			words[a][1]=word[strlen(word)-1];
		}
		memset(visit,0,sizeof(visit));
		int ans=bfs(a+1);
		if(ans==1){
			printf("Yes.\n");
		}
		else{
			printf("No.\n");
		}
	}
	return 0;
}
