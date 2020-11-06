#include<stdio.h>
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF){
	if(t<=100&&t>=0){
		if(t>=90){
			printf("A");
		}
		else if(t>=80){
			printf("B");
		}
		else if(t>=70){
			printf("C");
		}
		else if(t>=60){
			printf("D");
		}
		else if(t<60){
			printf("E");
		}
	}
	else{
		printf("Score is error!");
	}
	printf("\n");
}
	return 0;
}
