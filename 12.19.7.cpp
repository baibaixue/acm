#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
int main(){
	int pa1,pa2=0,pb1,pb2=0;
	scanf("%d%d",&pa1,&pb1);
	int x;
	for(int i=0;i<3;i++){
		scanf("%d",&x);
		if(x==1){
			pb2++;
		}else{
			pa2++;
		}
	}
	if(pa1>pb1){
		if(pa2!=0){
			printf("The winner is a: %d + %d\n",pa1,pa2);
		}else{
			printf("The winner is b: %d + %d\n",pb1,pb2);
		}
	}else if(pa1<pb1){
		if(pb2!=0){
			printf("The winner is b: %d + %d\n",pb1,pb2);
		}else{
			printf("The winner is a: %d + %d\n",pa1,pa2);
		}
	}
	return 0;
}
