#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int n;
	int a,b;
	int k=1;
	int cnt=0;
	scanf("%d",&n);
	scanf("%d",&a);
	for(int i=1;i<n;i++){
		scanf("%d",&b);
		if(b>a){
			k++;
		}else{
			if(k>cnt){
				cnt=k;
			}
			k=1;
		}
		a=b;
	}
	printf("%d\n",cnt);
	return 0;
} 
