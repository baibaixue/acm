#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define maxn 100005
using namespace std;
long long a[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	printf("%lld",a[0]);
	for(int i=1;i<n;i++){
		printf(" %lld",a[i]);
	}
	printf("\n");
	return 0;
}
