#include<stdio.h>//rabbit的寻宝一//2018新生杯 
#include<algorithm>
#define maxn 1020
using namespace std;
char s[maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int len;
		for(len=0;s[len]!='\0';len++);
		sort(s,s+len);
		for(int i=0;i<len;i++){
			if(s[i]>=65){
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
