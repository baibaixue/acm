#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#define maxn 10005
using namespace std;
struct A{
	char s[10];
	int x;
}num[maxn];
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%s",num[i].s);
		scanf("%d",&num[i].x);
		sum+=num[i].x;
		getchar();
	}
	int ave=sum/(2*n);
	int minn=(int)fabs(num[0].x-ave);
	int ans=0;
	for(int i=1;i<n;i++){
		if((int)fabs(num[i].x-ave)<minn){
			minn=(int)fabs(num[i].x-ave);
			ans=i;
		}
	}
	printf("%d %s\n",ave,num[ans].s);
	return 0;
}
