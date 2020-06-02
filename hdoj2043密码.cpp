#include<stdio.h>
#include<string.h>
#include<ctype.h> 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			char c[60];
			scanf("%s",c);
			int len=strlen(c);
			int a=0,b=0,x=0,d=0;
			if(len>=8&&len<=16){
				for(int i=0;i<len;i++){
					if(isupper(c[i])){
						a=1;
					}if(isdigit(c[i])){
						b=1;
					}if(c[i]>='a'&&c[i]<='z'){
						x=1;
					}if(c[i]=='~'||c[i]=='!'||c[i]=='@'||c[i]=='#'||c[i]=='$'||c[i]=='%'||c[i]=='^'){
						d=1;
					}
				}
			}
			if(a+b+x+d>=3){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0; 
} 
