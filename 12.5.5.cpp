#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std; 
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(b==0){
			printf("%d/%d=Error\n",a,b);
		}
		else if(b<0){
			printf("%d/(%d)=%.2f\n",a,b,a*1.0/b*1.0);
		}else if(b>0){
			printf("%d/%d=%.2f\n",a,b,a*1.0/b*1.0);
		}
	}
	return 0;
}
