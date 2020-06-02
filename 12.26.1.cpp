#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	char c;
	scanf("%c",&c);
	int a=n-1;
	int x=1;
	for(int i=3;;i+=2){
		if(a-2*i>=0){
			x=i;
			a=a-2*i;
		}else{
			break;
		}
	}
	for(int i=x;i>=1;i-=2){
		for(int j=0;j<x-i;j+=2){
			printf(" ");
		}
		for(int j=i;j>0;j--){
			printf("%c",c);
		}
//		for(int j=0;j<x-i;j+=2){
//			printf(" ");
//		}
		printf("\n");
	}
	for(int i=3;i<=x;i+=2){
		for(int j=0;j<x-i;j+=2){
			printf(" ");
		}
		for(int j=i;j>0;j--){
			printf("%c",c);
		}
//		for(int j=0;j<x-i;j+=2){
//			printf(" ");
//		}
		printf("\n");
	}
	printf("%d\n",a);
} 
