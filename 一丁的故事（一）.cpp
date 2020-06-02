#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int n;
	char s[35];
	scanf("%d",&n);
	while(n--){
		memset(s,0,sizeof(s));
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]>='A'&&s[i]<='Z'){
				printf("%c",s[i]+32);
			}else{
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
