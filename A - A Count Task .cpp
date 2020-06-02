#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char s[1000005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(s,0,sizeof(s));
		scanf("%s",s);
		long long res=0;
		for(int i=0;s[i];i++){
			long long cnt=1;
			while(s[i+1]&&s[i]==s[i+1]){
				i++;
				cnt++;
			}
			res+=(cnt+1)*cnt/2;
		}
		printf("%lld\n",res);
	}
}
