#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<cmath>
#define maxn 10005
#define M pow(2,31)
using namespace std;
long long num[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]); 
	}
	long long first=num[0];
	long long next=num[1];
	int a=0,b=1;
	long long sum=0;
	for(int j=1;j<n;j++){
		for(int i=0;i<n;i++){
			if(num[i]<first&&num[i]!=0){
				next=first;
				b=a;
				first=num[i];
				a=i;
			}
		}
		sum=sum+first+next;
		num[a]=sum;
		num[b]=0;
		first=num[j+1];
		next=num[a];
	}
	printf("%lld\n",sum);
	return 0;
}
