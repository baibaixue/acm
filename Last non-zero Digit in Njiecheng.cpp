#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10005
using namespace std;
int firsten[10]={1,1,2,6,4,2,2,4,2,8};
int right[10]={6,6,2,6,4,4,4,8,4,6};
int circles[10]={0,0,6,0,2,0,8,0,4,0};
int c(int n);
int f(int n){
	if((n%5)==0){
		return 1;
	}else{
		return f(n/5)*c(n)%10;
	}
}
int c(int n){
	int g=n%10;
	int C;
	for(int i=1;i<=(n/5);i++){
		C=circles[g];
		g=C;
	}
	return C;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n<10){
			printf("%d\n",firsten[n]);
		}else{
			printf("%d\n",f(n));
		}
	}
	return 0;
}
