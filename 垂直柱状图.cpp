#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int c[26];
	char s[1000];
	memset(c,0,sizeof(c));
	for(int i=0;i<4;i++){
			cin.getline(s,1000);
		//	getchar();
			for(int i=0;s[i]!='\0';i++){
				char x=s[i];
				if(x>='A'&&x<='Z'){
					c[(int)(x-'A')]++;
				}
		}
	}
	int max=0;
	for(int i=0;i<26;i++){
		if(max<c[i]){
			max=c[i];
		}
	}
	for(int i=max-1;i>=0;i--){
		for(int j=0;j<26;j++){
			if(c[j]>i){
				printf("*");
			}else{
				printf(" ");
			}
			if(j!=26){
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
	return 0;
	
}
