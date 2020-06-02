#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 1002
using namespace std;
int  main(){
	int num[maxn]={1,1,2,2,4,4};
	int sum[maxn]={1,2,4,6,10};
	for(int i=4;i<=maxn;i++){
		num[i]=sum[i/2];
		sum[i]=sum[i-1]+num[i];
	}
	int n;
	scanf("%d",&n);
	printf("%d\n",num[n]);
	return 0;
}




