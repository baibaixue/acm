#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int number[2000]={6,2,5,5,4,5,6,3,7,6};
int main(){ 
	int n;
	for(int i=10;i<2000;i++){
		number[i]=0;
		int a=i;
		while(a>0){
			number[i]+=number[a%10];
			a=a/10; 
		}
	}
	scanf("%d",&n);
	n=n-4;
	int cnt=0;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			if(n==number[i]+number[j]+number[i+j]){
				cnt++;	
			}
		}
	}
	//cout<<cnt<<"\n";
	printf("%d\n",cnt);
	return 0;
}
