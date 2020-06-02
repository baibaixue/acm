#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int num[105];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	int cnt=1;
	for(int i=1;i<n;i++){
		if(num[i]!=num[i-1]){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	printf("%d",num[0]);
	for(int i=1;i<n;i++){
		if(num[i]!=num[i-1]){
			printf(" %d",num[i]);
		}
	}
	printf("\n");
	return 0;
} 
