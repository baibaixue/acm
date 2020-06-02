#include <stdio.h>

int main() 
{
	const int number=100;
	int i;
	int prime[number];
	for (i=0;i<number;i++){
		prime[i]=1;
	} 
	int x=2;
	while(x<number){
		if (prime[x]){
			for(i=2;x*i<number;i++){
				prime[x*i]=0;
			}
		}
		x++;
	}
	for (i=2;i<number;i++){
		if (prime[i]){
			printf("%d\t",i);
		}
	}
	printf("%d");
	
	return 0;
}

