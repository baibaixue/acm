//白雪，水仙花数 
#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	int a,b,c,t,count=0;
	for(i=100;i<=999;i++){//三位数循环 
		a=i/100;//百位数 
		t=i%100;
		b=t/10;//十位数 
		c=t%10;//个位数 
		if(i==pow(a,3)+pow(b,3)+pow(c,3)){
			if(count==0){
				printf("%d",i);
			}
		else{
			printf(" %d",i);
		}//每两个数之间有一个空格 
		count+=1;
		}
	}
	printf("\n");
	return 0;
 } 
