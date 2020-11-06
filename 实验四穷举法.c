//10月29号，白雪，穷举法求整数解
#include<stdio.h>
int main(){
	int i,j;
	for(i=0;i<33;i++){//x不超过33，依次遍历 
		for(j=0;j<33;j++){
			if(i*i+j*j==1000){//判断并输出 
				printf("x=%d,y=%d\n",i,j);
			}
		}
	}
	return 0;
} 
