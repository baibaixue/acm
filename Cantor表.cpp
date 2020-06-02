#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int fenmu(int n){
	for(int i=2;;i+=2){
		if(n-i*2+1>0){
			n=n-i*2+1;
		}else{
			if(n<=i){
				return n;
			}else{
				return 2*i-n;
			}
		}
	}
}
int fenzi(int n){
	for(int i=1;;i+=2){
		if(n-i*2+1>0){
			n=n-i*2+1;
		}else{
			if(n<=i){
				return n;
			}else{
				return 2*i-n;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d/%d\n",fenzi(n),fenmu(n));
	return 0;
}
