#include<cstdio>
#include<iostream>
#include<string.h>
#define maxn 10005
using namespace std;
int a[maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int k=1;
		int max=0;
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1]+1){
				k++;
			}else{
				k=1;
			}
			if(max<k){
				max=k;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
