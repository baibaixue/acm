#include <stdio.h>

	int isprime(int x,int prime[],int count);
	
	int main(){
		const int number=10;
		int prime[number]={2};
		int x=3;
		int count=1;
		{
			int i;
			printf("\t\t");
			for (i=0;i<number;i++){
				printf("%d  ",i);
			}
			printf("\n");
		}
		while (count<number){
			if(isprime(x,prime,count)){
				prime[count++]=x;
			}
			printf("x=%d   count=%d   ",x,count);
			{
				int i;
				for(i=0;i<number;i++){
					printf("%d  ",prime[i]);
				}
				printf("\n");
			}
			x++;
		}
	
	//for (x=0;x<count;x++){
		//printf("%d\n",prime[x]);
		//} 
		//if((x+1)%5) printf("\t");
		//else printf("\n");
	}
	
	int isprime(int x,int prime[],int count){
		int i;
		int ret=1;
		for (i=0;i<count;i++){
			if (x%prime[i]==0){
				ret=0;
				break;
		}
	}
	return ret;
 } 
