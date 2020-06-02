#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	char s[100];
	cin.getline(s,100);
	int len=strlen(s);
	int is_float=0,is_fen=0,is_bai=0;
	long long a=0,b=0;
	for(int i=len-1;i>=0;i--){
		if(s[i]=='.'){
			is_float=1;
		}else if(s[i]=='/'){
			is_fen=1;
		}else if(s[i]=='%'){
			is_bai=1;
		}
		else if(is_float!=0||is_fen!=0){
			b=b*10+(int)(s[i]-'0');
		}else{
			a=a*10+(int)(s[i]-'0');
		}
	}
	if(is_float==1||is_fen==1){
		while(1){
			if(a%10!=0||a==0){
				break;
			}else{
				a=a/10;
			}
		}
	}
	if(is_float==1){
		printf("%lld.%lld",b,a);
	}else if(is_fen==1){
		printf("%lld/%lld",b,a);
	}else if(is_bai==1){
		printf("%lld",a);
		cout<<"%";
	}else{
		printf("%lld",a);
	}
	printf("\n");
	return 0;
}
