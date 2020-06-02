#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			int h;
			scanf("%d",&h);
			double w;
			w=(h-100)*0.9;
			double W;
			scanf("%lf",&W);
			W=W/2.0;
			double xw=W*1.0-w;
			if(xw<0){
				xw=-xw;
			}
			if(xw<(w*0.1)){
				printf("You are wan mei!\n");
			}else{
				if(W*1.0-w>0){
					printf("You are tai pang le!\n");
				}else{
					printf("You are tai shou le!\n");
				}
			}
		}
	}
	return 0;
}
