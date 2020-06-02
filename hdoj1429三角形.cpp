#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",3*n*(n-1)+2);
	}
	return 0;
}
