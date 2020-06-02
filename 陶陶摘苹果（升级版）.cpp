#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct node{
	int xi;
	int yi;
}app[5005];
int cmp(node a,node b){
	return a.yi<b.yi;
}
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	int a,b,l;
	scanf("%d%d",&a,&b);
	l=a+b;
	for(int i=0;i<n;i++){
		scanf("%d%d",&app[i].xi,&app[i].yi);
	}
	int cnt=0;
	sort(app,app+n,cmp);
	for(int i=0;i<n;i++){
		if(s>=app[i].yi&&app[i].xi<=l){
			cnt++;
			s=s-app[i].yi;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
