#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
char N[10][5]={{"ling"},{"yi"},{"er"},{"san"},{"si"},{"wu"},{"liu"},{"qi"},{"ba"},{"jiu"}};
char num[100];
int main(){
	scanf("%s",num);
	int len=strlen(num);
	if(num[0]=='-'){
		printf("fu");
	}else{
		printf("%s",N[(int)(num[0]-'0')]);
	}
	for(int i=1;i<len;i++){
		printf(" %s",N[(int)(num[i]-'0')]);
	}
	printf("\n");
	return 0;
} 
