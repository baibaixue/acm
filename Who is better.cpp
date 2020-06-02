#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n1,n2,p1,p2,s1,s2;
	scanf("%d%d%d%d%d%d",&n1,&p1,&s1,&n2,&p2,&s2);
	if(n1>n2){
		printf("1\n");
	}else if(n1<n2){
		printf("2\n");
	}else{
		if(p1<p2){
			printf("1\n");
		}else if(p1>p2){
			printf("2\n");
		}else{
			if(s1<s2){
				printf("1\n");
			}else if(s1>s2){
				printf("2\n");
			}else{
				printf("God\n");
			}
		}
	}
} 
