#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std; 
int main(){
	int y,m,d;
	while(scanf("%d-%d-%d",&m,&d,&y)!=EOF){
		printf("%04d-%02d-%02d\n",y,m,d);
	}
	return 0;
}
