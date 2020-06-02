#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 1005
using namespace std;
int memory[maxn];
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	queue<int> Q;
	memset(memory,0,sizeof(memory));
	int letter;
	int ans=0;
	int k=0;
	for(int i=0;i<n;i++){
		scanf("%d",&letter);
		if(memory[letter]==0){
			if(m>0){
				ans++;
				memory[letter]=1;
				Q.push(letter);
				m--;
			}else if(m==0){
				int a=Q.front();
				Q.pop(); 
				memory[a]=0;
				memory[letter]=1;
				Q.push(letter);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
