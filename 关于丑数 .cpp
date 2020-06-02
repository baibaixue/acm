#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a;
		scanf("%d",&a);
		int ok=1;
		while(a!=1){
			if(a%2==0){
				a=a/2;
			}else if(a%3==0){
				a=a/3;
			}else if(a%5==0){
				a=a/5;
			}else if(a%7==0){
				a=a/7;
			}else{
				ok=0;
				break;
			}
		}
		if(a==1){
			ok=1;
		}
		if(ok==1){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
