#include <stdio.h>

int main(){
	int a=12;
	int*p=&a;
	printf("*p=%d p=%d",*p,p);
	return 0; 
}
