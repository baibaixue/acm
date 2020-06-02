#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
int is_prime(long long n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	for(long long i=1;i<=20000;i++){
		if(is_prime(i)==1){
			printf("%lld,",i);
		}
	}
	return 0;
}
