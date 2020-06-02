#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int sum=0;
	int k=5;
	for(int i=a;i<=b;i++){
		if(k!=0){
			printf("%5d",i);
			sum+=i;
			k--;
		}else if(k==0){
			printf("\n");
			printf("%5d",i);
			k=4;
			sum+=i;
		}
	}
		printf("\n");
	printf("Sum = %d\n",sum);
	return 0;
} 
