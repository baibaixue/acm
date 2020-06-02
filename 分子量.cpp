#include<stdio.h>
#include<ctype.h>
#include<string.h> 
char s[20];
int main(){
	while(scanf("%s",s)!=EOF){
		double quality=0;
		double C=12.01,H=1.008,O=16.00,N=14.01;
		for(int i=0;i<strlen(s);i++){
			if(isalpha(s[i])&&isdigit(s[i+1])){
				switch(s[i]){ 
					case 'C':quality+=C*(s[i+1]-'0');break;
					case 'H':quality+=H*(s[i+1]-'0');break;
					case 'O':quality+=O*(s[i+1]-'0');break;
					case 'N':quality+=N*(s[i-1]-'0');break;
				}
			}
			else if(isalpha(s[i])&&!isdigit(s[i+1])){
				switch(s[i]){
					case 'C':quality+=C;break;
					case 'H':quality+=H;break;
					case 'O':quality+=O;break;
					case 'N':quality+=N;break;
				}
			}
		}
		printf("%.3f\n",quality);
	}
} 
