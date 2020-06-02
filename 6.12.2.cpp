#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std; 
int n;
int main(){
	scanf("%d",&n);
	while(n--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int e=a*c,f=b*d;
		int A=e,B=f;
		int x;
		while(B!=0){
			x=A%B;
			A=B;
			B=x;
		}
		e=e/A;
		f=f/A;
		
		printf("%d %d\n",e,f);
	}
}
