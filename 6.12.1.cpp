#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n;
int main(){
	int l,t1,t2,v1,v2;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d%d",&l,&t1,&t2,&v1,&v2);
		double T1,T2;
		T1=t1+t2+(l*1.0/v1*1.0);
		T2=l*1.0/v2*1.0;
		if(T1>T2){
			printf("Walk is OK!\n");
		}else if(T1<T2){
			printf("Bike is OK!\n");
		}else{
			printf("Both are OK!\n");
		}
	}
}
