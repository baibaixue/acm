#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n[7];
	int a,b;
	for(int i=0;i<7;i++){
		scanf("%d%d",&a,&b);
		n[i]=a+b;
	}
	int x=0;
	int max=0;
	for(int i=0;i<7;i++){
		if(n[i]>8&&n[i]>max){
			max=n[i];
			x=i;
		}
	}
	if(max==0){
		printf("0\n");
	}else{
		printf("%d\n",x+1);
	}
	return 0;
}
