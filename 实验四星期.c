//10月29日，白雪，输出周一到周日
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);//测试数据5 
	switch(n){
		case 1:printf("星期一\n");break;
		case 2:printf("星期二\n");break;
		case 3:printf("星期三\n");break;
		case 4:printf("星期四\n");break;
		case 5:printf("星期五\n");break;//结果星期五 
		case 6:printf("星期六\n");break;
		case 7:printf("星期天\n");break; //分各个情况输出 
	}
	return 0;
} 
