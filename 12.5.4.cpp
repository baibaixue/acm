#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std; 
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int ans;
		ans=a*b;
		printf("%d\n",ans);
	}
	return 0;
}
