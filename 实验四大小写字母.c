//10月29日，白雪，两种循环语句输大小写字母
#include<stdio.h>
int main(){
	char c='A';
	char t='a';
	int i;
	for(i=0;i<26;i++){//第一种循环 
		printf("%c ",c++); 
	}
	printf("\n");
	while(t<='z'){//第二种循环 
		printf("%c ",t++);
	}
	printf("\n");
	return 0;
} 
