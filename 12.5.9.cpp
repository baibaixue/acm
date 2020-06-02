#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 100005
using namespace std;
int num[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		sort(num,num+n);
		int out=0,in=0;
		if(n%2==0){
			for(int i=0;i<n/2;i++){
				in+=num[i];
				out+=num[n-i-1];
			}
			printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n",n/2,n/2,out-in);
		}else{
			for(int i=0;i<n/2;i++){
				in+=num[i];
				out+=num[n-i-1];
			}
			out+=num[n/2];
			printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n",n/2+1,n/2,out-in);
		}
	}
	return 0; 
}
