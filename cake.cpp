#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
//#define maxn 1000000
using namespace std;
//int piece[maxn];
int gongyinshu(int a,int b){
	int x=a%b;
	while(x!=0){
		a=b;
		b=x;
		x=a%b;
	}
	return b;
}
int main(){
	int p,q;
	while(scanf("%d%d",&p,&q)!=EOF){
		int count;
		count=p+q-gongyinshu(p,q);
		//int num=p*q/gongyinshu(p,q);
		//memset(piece,0,sizeof(piece));
		//int n=num/p,m=num/q;
		//for(int i=n;i<=num;i+=n){
		//	piece[i]=1;
		//}
		//for(int j=m;j<=num;j+=m){
		//	piece[j]=1;
		//}
		//int count=0;
		//for(int i=1;i<=num;i++){
		//	if(piece[i]==1){
		//		count++;
		//	}
		//}
		printf("%d\n",count);
	}
	return 0;
}
