#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define maxn 100005
#define inf 0x3f3f3f3f
using namespace std;
char s[maxn];
int main(){
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		for(int i=0;i<len-1;i++){
			if((s[i]=='i'&&s[i+1]=='g')||(s[i]=='I'&&s[i+1]=='G')||(s[i]=='I'&&s[i+1]=='g')){
				printf("iG");
				i++;
			}else{
				printf("%c",s[i]);
			}
		}
		if((s[len-2]!='i'&&s[len-1]!='g')||(s[len-2]!='I'&&s[len-1]!='G')||(s[len-2]!='I'&&s[len-1]!='G')){
			printf("%c",s[len-1]);
		}
		printf("\n");
	}
}
