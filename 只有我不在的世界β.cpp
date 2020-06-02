#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
//int A[1001]; 
//int low(int a,b){
//	int A=a,B=b;
//	int x;
//	while(b!=0){
//		x=a%b;
//		a=b;
//		b=x;
//	}
//	return (A*B)/b;
//}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int b;
		scanf("%d",&b);
		int k=0;
		for(int i=1;i<=min(b,1000);i++){
			if(b%i==0){
				k++;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}

