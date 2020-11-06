#include<stdio.h>//统计字符a 11月19日 白雪 
int main(){
	char s[10000];
	int i;
	for(i=0;;i++){
		scanf("%c",&s[i]);//输入字符 
		if(s[i]=='\n'){
			break;
		}
	}
	int count=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='a'){//统计字符 
			count++;//计数 
		}
	}
	printf("%d\n",count);
	return 0;	
}
