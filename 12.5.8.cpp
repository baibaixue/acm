#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std; 
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	char s;
	double h;
	for(int i=0;i<n;i++){
		scanf("%c",&s);
		scanf("%lf",&h);
		getchar();
		if(s=='M'){
			printf("%.2f\n",h/1.09);
		}if(s=='F'){
			printf("%.2f\n",h*1.09);
		}
	}
	return 0; 
}
